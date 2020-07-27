"""
Copyright (c) 2019 Ash Wilding. All rights reserved.

SPDX-License-Identifier: MIT

This script builds the library from the AArch64 System Register XML.

Usage:

    python3.8 run-build.py XML_PATH

Example:

    curl -O https://developer.arm.com/-/media/developer/products/architecture/armv8-a-architecture/2020-06/SysReg_xml_v86A-2020-06.tar.gz
    tar xf SysReg_xml_v86A-2020-06.tar.gz
    python3.8 run-build.py SysReg_xml_v86A-2020-06

"""

import bs4
import os
import shutil
import sys
from functools import reduce

"""
Cannot directly use these escaped literals in f-string exprs, so store them in
variables and refer to them instead.
"""
NEWLINE = '\n'
BACKSLASH = '\\'

"""
Every generated header file will include this preamble.
"""
PREAMBLE = f"""
/*
 * This file was automatically generated using arm64-sysreg-lib
 * See: https://github.com/ashwio/arm64-sysreg-lib
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ARM64_SYSREG_MACROS_DEFINED
#define ARM64_SYSREG_MACROS_DEFINED

/*
 * These macros are inspired by Daniel Hardman's Variadic Macro Tricks blog:
 * https://codecraft.co/2014/11/25/variadic-macros-tricks/
 *
 * The net result is ARM64_SYSREG_CALL_FOR_EACH( m, ... ) calling the macro, m,
 * for each token in the variadic args list, ..., which we use to set a variadic
 * list of struct fields.
 *
 * For example:
 *
 *      safe_write_sctlr_el1( .m=1, .c=1, .i=1, .lsmaoe=0, );
 *
 * Where the safe_write_*() functions copy the system register's known SAFEVAL,
 * which has all currently or previously RES1 bits set to 1 and all currently or
 * previously RES0 bits cleared to 0, then overwrite the fields specified in the
 * variadic arg list before performing an MSR.
 *
 * A maximum of 64 fields can be passed in this way, which should be fine given
 * that an AArch64 system register is either 32 or 64 bits wide, and each field
 * must itself be at least 1 bit wide.
 */

#define ARM64_SYSREG_GET_ARG_N( \\
{NEWLINE.join([f"    _{i}, {BACKSLASH}" for i in range(1, 64)])}
    N, ... ) N

#define ARM64_SYSREG_CALL_FOR_ARG0( _call, ... )
#define ARM64_SYSREG_CALL_FOR_ARG1( _call, x ) _call(x)
{NEWLINE.join([
    f"#define ARM64_SYSREG_CALL_FOR_ARG{i}( _call, x, ... ) " +
    f"_call(x) ARM64_SYSREG_CALL_FOR_ARG{i-1}(_call, __VA_ARGS__)"
    for i in range(2, 63)])}

#define ARM64_SYSREG_CALL_FOR_EACH( m, ... ) \\
    ARM64_SYSREG_GET_ARG_N("placeholder", __VA_ARGS__, \\
{NEWLINE.join([f"        ARM64_SYSREG_CALL_FOR_ARG{i}, {BACKSLASH}" for i in range(62, -1, -1)])}
    )(m, __VA_ARGS__)

#define ARM64_SYSREG_SET( arg ) tmp arg;

/*
 * Manually typedef u64 in case compiler doesn't have <stdint.h> (have seen
 * this with compilers installed on MacOS, both via Xcode and Homebrew).
 * Vast majority users target __LP64__ so only bother supporting this for now.
 */
#ifdef __LP64__
    typedef unsigned long u64;
#else
    #error "Unrecognised compilation target ABI, expected LP64"
#endif

/* ARM64_SYSREG_MACROS_DEFINED */
#endif

/*========================================================================*
 *  AUTOMATICALLY GENERATED SYSTEM REGISTER CODE FROM THIS POINT ONWARDS  *
 *========================================================================*/
"""


class AArch64XML(bs4.BeautifulSoup):
    """ Wrapper around BeautifulSoup for easier parsing of AArch64 XML. """

    class ParseError(Exception):
        """ Base class of exceptions raised while parsing AArch64 XML. """
        registered_errors = {}

        def __init__( self, xml_node:bs4.BeautifulSoup, message:str="No specific error info" ) -> None:
            self.xml_node = xml_node
            self.message = message
            if message in self.__class__.registered_errors:
                self.__class__.registered_errors[message] += 1
            else:
                self.__class__.registered_errors[message] = 1

        def __str__( self ) -> str:
            return f"\n\n{self.xml_node}\n\n{type(self).__name__}{': '+self.message if self.message else ''}"

    class AttrValueError(ParseError):
        """ Raised when an XML node has an attribute value that we don't yet know how to handle. """
        pass

    class NumChildrenError(ParseError):
        """ Raised when an XML node does not have the expected number of children. """
        pass

    def assert_attr_equals( self, attr:str, expected_value:str ) -> None:
        if not self[attr] == expected_value:
            raise AArch64XML.AttrValueError(self, f'xml["{attr}"]={self[attr]}')

    def assert_child_exists( self, child:str ) -> None:
        children = self.find_all_exact(child)
        if not(type(children) is list and len(children) > 0):
            raise AArch64XML.NumChildrenError(self, f"no '{child}' child node")

    def assert_str_not_numbered( self, s:str, entity:str, spaces_ok:bool=False ) -> None:
        if not spaces_ok:
            if len(s.split()) > 1:
                raise AArch64XML.AttrValueError(self, f"{entity} name has spaces")
        if '<' in s:
            raise AArch64XML.AttrValueError(self, f"{entity} name contains {s[s.find('<'):s.find('>')+1]}")

    def find_all_exact( self, child:str, assert_only_one:bool=False ):
        """
        Wrapper around BeautifulSoup's find_all(), but only returning exact
        matches.

        Further, can optionally build in an assertion that only a single child
        node is returned. In this case, that child node itself is returned
        rather than a single-element list.
        """
        children = [c for c in self.find_all(child) if c.name == child]
        for c in children:
            c.__class__ = AArch64XML
        if assert_only_one:
            if len(children) == 1:
                return children[0]
            else:
                raise AArch64XML.NumChildrenError(self, f"expected 1x '{child}' child node but got {'more' if len(children) > 1 else 'none'}")
        return children

    def attr_exists( self, attr:str ) -> bool:
        """ bs4 doesn't support 'if x in y' so use a try/except clause instead. """
        try:
            probe = self[attr]
        except KeyError:
            return False
        return True


class Field():
    """ Class representing a bitfield in a system register. """

    def __init__( self, xml:AArch64XML ):
        self.msb = int(xml.field_msb.string)
        self.lsb = int(xml.field_lsb.string)
        self.res = 0

        xml.assert_attr_equals('is_variable_length', 'False')
        xml.assert_attr_equals('has_partial_fieldset', 'False')
        xml.assert_attr_equals('is_linked_to_partial_fieldset', 'False')

        def get_res( s:str ) -> int:
            if s.startswith("RES"):
                return int(s[-1])
            elif s.startswith("RAZ") or s.startswith("UNKNOWN"):
                return 0
            elif s.startswith("RAO"):
                return 1
            else:
                raise ValueError

        try:
            if xml.attr_exists('rwtype'):
                self.res = get_res(xml['rwtype'])
                self.name = f'res{self.res}_{self.msb}' + ('' if self.msb == self.lsb else f'_{self.lsb}')
            else:
                self.name = xml.field_name.string.lower()
                if xml.attr_exists('reserved_type'):
                    self.res = get_res(xml['reserved_type'])
        except ValueError as e:
            raise AArch64XML.AttrValueError(xml, f"parsing field rwtype/reserved_type")
        except AttributeError as e:
            self.name = xml.find_all_exact("field_shortdesc", assert_only_one=True).string

        xml.assert_str_not_numbered(self.name, "field", spaces_ok=True)
        for c in [' ', '[', ':', ']']:
            self.name = self.name.replace(c, '_')

        if self.name == "implementation_defined":
            self.name = f"impdef_{self.msb}{f'_{self.lsb}' if self.msb > self.lsb else ''}"

    @property
    def decl( self ) -> str:
        return f"""
        u64 {self.name} : {self.msb - self.lsb + 1};"""

    @property
    def safeval( self ) -> str:
        return '' if self.res == 0 else f"""
    .{self.name} = {(1 << (self.msb - self.lsb + 1)) - 1},"""


class Register():
    """ Class representing a system register. """

    def __init__( self, xml_path:str ):
        with open(xml_path) as xml_file:
            xml = bs4.BeautifulSoup(xml_file.read(), features='html.parser')
        xml.__class__ = AArch64XML
        xml.assert_child_exists('register_page')
        xml = xml.register_page
        xml.assert_child_exists('registers')
        xml = xml.registers

        xml = xml.find_all_exact('register', assert_only_one=True)
        xml.assert_attr_equals('execution_state', 'AArch64')

        self.name = xml.reg_short_name.string.lower()
        xml.assert_str_not_numbered(self.name, "register")

        self.fields = []
        fields = xml.find_all_exact('fields', assert_only_one=True)
        for field_xml in fields.find_all_exact('field'):
            f = Field(field_xml)
            if not self.fields:
                self.fields.append(f)
            else:
                """ Only append if this is a new field. """
                if not f.msb == self.fields[-1].msb:
                    self.fields.append(f)
        self.fields.reverse()

        self.ops = {}
        self.readable = False
        self.writeable = False
        access_mechanisms = xml.find_all_exact('access_mechanisms', assert_only_one=True)
        for am_xml in access_mechanisms.find_all_exact('access_mechanism'):
            accessor_name = am_xml['accessor'].lower()
            if accessor_name.endswith(self.name) or accessor_name.replace("icc_", "icv_").endswith(self.name):
                if not self.ops:
                    for enc_xml in am_xml.find_all_exact('enc'):
                        self.ops[enc_xml['n']] = int(enc_xml['v'][2:], 2)

                if not self.readable:
                    if am_xml['accessor'].startswith("MRS"):
                        self.readable = True

                if not self.writeable:
                    if am_xml['accessor'].startswith("MSR"):
                        self.writeable = True

        if not self.readable and not self.writeable:
            raise AArch64XML.ParseError(access_mechanisms, "no accessors")


    @property
    def decl( self ) -> str:
        return f"""

union {self.name}
{{
    u64 _;
    __extension__ struct {{{"".join([f.decl for f in self.fields])}
    }};
}};
"""

    @property
    def safeval( self ) -> str:
        if not self.writeable:
            return ""
        else:
            fields = "".join([f.safeval for f in self.fields])
            if not fields:
                fields = "0"
            return f"""

static const union {self.name} {self.name.upper()}_SAFEVAL =
{{{fields}
}};
"""

    @property
    def encoding( self ) -> str:
        return f's{r.ops["op0"]}_{r.ops["op1"]}_c{r.ops["CRn"]}_c{r.ops["CRm"]}_{r.ops["op2"]}'

    @property
    def read( self ) -> str:
        return '' if not self.readable else f"""

static inline union {self.name} read_{self.name}( void )
{{
    union {self.name} tmp;
    __asm(
        "MRS %0, {self.encoding}"
        : "=r" (tmp._)
    );
    return tmp;
}}
"""

    @property
    def unsafe_write( self ) -> str:
        return '' if not self.writeable else f"""

static inline void unsafe_write_{self.name}( union {self.name} val )
{{
    __asm(
        "MSR {self.encoding}, %0"
        : /**/ : "r" (val._)
    );
}}
"""

    @property
    def safe_write( self ) -> str:
        return "" if not self.writeable else f"""

#define safe_write_{self.name}( ... ) \\
    do \\
    {{ \\
        union {self.name} tmp = {self.name.upper()}_SAFEVAL; \\
        ARM64_SYSREG_CALL_FOR_EACH(ARM64_SYSREG_SET, __VA_ARGS__) \\
        unsafe_write_{self.name}(tmp); \\
    }} while (0)
"""

    @property
    def read_modify_write( self ) -> str:
        return "" if not (self.readable and self.writeable) else f"""

#define read_modify_write_{self.name}( ... ) \\
    do \\
    {{ \\
        union {self.name} tmp = read_{self.name}(); \\
        ARM64_SYSREG_CALL_FOR_EACH(ARM64_SYSREG_SET, __VA_ARGS__) \\
        unsafe_write_{self.name}(tmp); \\
    }} while (0)
"""

    @property
    def test_read( self ) -> str:
        return "" if not self.readable else f"""
u64 test_read_{self.name}( void )
{{
    return read_{self.name}().{self.fields[0].name};
}}
"""

    @property
    def test_unsafe_write( self ) -> str:
        return "" if not self.writeable else f"""
void test_unsafe_write_{self.name}( void )
{{
    unsafe_write_{self.name}((union {self.name}){{ .{self.fields[0].name}=1 }});
}}
"""

    @property
    def test_safe_write( self ) -> str:
        return "" if not self.writeable else f"""
void test_safe_write_{self.name}( void )
{{
    safe_write_{self.name}( .{self.fields[0].name}=1 );
}}
"""

    @property
    def test_read_modify_write( self ) -> str:
        return "" if not (self.readable and self.writeable) else f"""
void test_read_modify_write_{self.name}( void )
{{
    read_modify_write_{self.name}( .{self.fields[0].name}=1 );
}}
"""

if __name__ == "__main__":
    if not len(sys.argv) == 2:
        print(f"example usage: python3.8 {sys.argv[0]} /path/to/xml/directory/")
        sys.exit(1)

    files = []
    try:
        for (_, _, f) in os.walk(sys.argv[1]):
            files.extend(f)
            break
    except OSError as e:
        print(e)
        sys.exit(e.errno if hasattr(e, "errno") else 1)

    def rmdir( path:str ) -> None:
        try:
            shutil.rmtree(path, ignore_errors=True)
        except OSError as e:
            sys.exit(e.errno if hasattr(e, "errno") else 1)

    def mkdir( path:str ) -> None:
        dirs = path.split("/")
        for i in range(len(dirs)):
            try:
                os.mkdir("/".join(dirs[:i+1]))
            except FileExistsError:
                pass
            except OSError as e:
                print(e)
                sys.exit(e.errno if hasattr(e, "errno") else 1)

    class FilenameFilter:
        instructions = ["ic", "dc", "tlbi", "at", "cfp", "cpp", "dvp"]
        counts = {}

        @classmethod
        def check( cls, path:str ) -> bool:
            if not path.startswith("AArch64-"):
                """ ignore AArch32 and external system registers """
                return False
            if path.startswith("AArch64-s1_") or path.startswith("AArch64-s3_"):
                """ ignore example instructions """
                return False
            if path.startswith("AArch64-sp_el3"):
                """ sp_el3 cannot be accessed using MRS/MSR """
                return False
            for instr in cls.instructions:
                """ ignore instructions that look like system registers """
                if not instr in cls.counts:
                    cls.counts[instr] = 0
                if path.startswith(f"AArch64-{instr}-"):
                    cls.counts[instr] += 1
                    return False
            return True

        @classmethod
        def report( cls ) -> str:
            ret = f"skipped {reduce(lambda a,b: a+b, cls.counts.values())} files corresponding to instructions:"
            for instr,count in cls.counts.items():
                ret += f"\n - {instr} (x{count})"
            return ret

    rmdir("include")
    rmdir("test")
    mkdir(f"include/sysreg")
    mkdir(f"test")

    ok = []
    failures = []
    print("========== build start ==========")
    for f in sorted(list(filter(FilenameFilter.check, files))):
        print(f"parsing {f}")
        try:
            r = Register(f"{sys.argv[1]}/{f}")
        except AArch64XML.ParseError as e:
            failures.append(f)
            print(e)
            print(f"failed to parse {f}: {e.message}\n\n")
        else:
            ok.append(f)
            with open(f"include/sysreg/{r.name}.h", "w") as header_file:
                header_file.write(f"""
{PREAMBLE}

#ifndef H_{r.name.upper()}
#define H_{r.name.upper()}

{r.decl}
{r.safeval}
{r.read}
{r.unsafe_write}
{r.safe_write}
{r.read_modify_write}

/* H_{r.name.upper()} */
#endif
""")

            with open(f"test/test_{r.name}.c", "w") as test_file:
                test_file.write(f"""

#include "sysreg/{r.name}.h"

{r.test_read}
{r.test_unsafe_write}
{r.test_safe_write}
{r.test_read_modify_write}
""")

    if failures:
        print("========== build failures ==========")
        print("\n".join(failures))

    print("========== build results ==========")
    print(FilenameFilter.report())
    print(f"successfully built {len(ok)} of the remaining {len(ok)+len(failures)} files ({len(failures)} errors)")

    if failures:
        print("NOTE: these error messages are expected! this tool is still in development")
        print("summary of issues the tool cannot yet parse:")
        keys = sorted(AArch64XML.ParseError.registered_errors.keys())
        for k in keys:
            print(f" - {k} (x{AArch64XML.ParseError.registered_errors[k]})'")

