

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

#define ARM64_SYSREG_GET_ARG_N( \
    _1, \
    _2, \
    _3, \
    _4, \
    _5, \
    _6, \
    _7, \
    _8, \
    _9, \
    _10, \
    _11, \
    _12, \
    _13, \
    _14, \
    _15, \
    _16, \
    _17, \
    _18, \
    _19, \
    _20, \
    _21, \
    _22, \
    _23, \
    _24, \
    _25, \
    _26, \
    _27, \
    _28, \
    _29, \
    _30, \
    _31, \
    _32, \
    _33, \
    _34, \
    _35, \
    _36, \
    _37, \
    _38, \
    _39, \
    _40, \
    _41, \
    _42, \
    _43, \
    _44, \
    _45, \
    _46, \
    _47, \
    _48, \
    _49, \
    _50, \
    _51, \
    _52, \
    _53, \
    _54, \
    _55, \
    _56, \
    _57, \
    _58, \
    _59, \
    _60, \
    _61, \
    _62, \
    _63, \
    N, ... ) N

#define ARM64_SYSREG_CALL_FOR_ARG0( _call, ... )
#define ARM64_SYSREG_CALL_FOR_ARG1( _call, x ) _call(x)
#define ARM64_SYSREG_CALL_FOR_ARG2( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG1(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG3( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG2(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG4( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG3(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG5( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG4(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG6( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG5(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG7( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG6(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG8( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG7(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG9( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG8(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG10( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG9(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG11( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG10(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG12( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG11(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG13( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG12(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG14( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG13(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG15( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG14(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG16( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG15(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG17( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG16(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG18( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG17(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG19( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG18(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG20( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG19(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG21( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG20(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG22( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG21(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG23( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG22(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG24( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG23(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG25( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG24(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG26( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG25(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG27( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG26(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG28( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG27(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG29( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG28(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG30( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG29(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG31( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG30(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG32( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG31(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG33( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG32(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG34( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG33(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG35( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG34(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG36( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG35(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG37( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG36(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG38( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG37(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG39( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG38(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG40( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG39(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG41( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG40(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG42( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG41(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG43( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG42(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG44( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG43(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG45( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG44(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG46( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG45(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG47( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG46(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG48( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG47(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG49( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG48(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG50( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG49(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG51( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG50(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG52( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG51(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG53( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG52(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG54( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG53(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG55( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG54(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG56( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG55(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG57( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG56(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG58( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG57(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG59( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG58(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG60( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG59(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG61( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG60(_call, __VA_ARGS__)
#define ARM64_SYSREG_CALL_FOR_ARG62( _call, x, ... ) _call(x) ARM64_SYSREG_CALL_FOR_ARG61(_call, __VA_ARGS__)

#define ARM64_SYSREG_CALL_FOR_EACH( m, ... ) \
    ARM64_SYSREG_GET_ARG_N("placeholder", __VA_ARGS__, \
        ARM64_SYSREG_CALL_FOR_ARG62, \
        ARM64_SYSREG_CALL_FOR_ARG61, \
        ARM64_SYSREG_CALL_FOR_ARG60, \
        ARM64_SYSREG_CALL_FOR_ARG59, \
        ARM64_SYSREG_CALL_FOR_ARG58, \
        ARM64_SYSREG_CALL_FOR_ARG57, \
        ARM64_SYSREG_CALL_FOR_ARG56, \
        ARM64_SYSREG_CALL_FOR_ARG55, \
        ARM64_SYSREG_CALL_FOR_ARG54, \
        ARM64_SYSREG_CALL_FOR_ARG53, \
        ARM64_SYSREG_CALL_FOR_ARG52, \
        ARM64_SYSREG_CALL_FOR_ARG51, \
        ARM64_SYSREG_CALL_FOR_ARG50, \
        ARM64_SYSREG_CALL_FOR_ARG49, \
        ARM64_SYSREG_CALL_FOR_ARG48, \
        ARM64_SYSREG_CALL_FOR_ARG47, \
        ARM64_SYSREG_CALL_FOR_ARG46, \
        ARM64_SYSREG_CALL_FOR_ARG45, \
        ARM64_SYSREG_CALL_FOR_ARG44, \
        ARM64_SYSREG_CALL_FOR_ARG43, \
        ARM64_SYSREG_CALL_FOR_ARG42, \
        ARM64_SYSREG_CALL_FOR_ARG41, \
        ARM64_SYSREG_CALL_FOR_ARG40, \
        ARM64_SYSREG_CALL_FOR_ARG39, \
        ARM64_SYSREG_CALL_FOR_ARG38, \
        ARM64_SYSREG_CALL_FOR_ARG37, \
        ARM64_SYSREG_CALL_FOR_ARG36, \
        ARM64_SYSREG_CALL_FOR_ARG35, \
        ARM64_SYSREG_CALL_FOR_ARG34, \
        ARM64_SYSREG_CALL_FOR_ARG33, \
        ARM64_SYSREG_CALL_FOR_ARG32, \
        ARM64_SYSREG_CALL_FOR_ARG31, \
        ARM64_SYSREG_CALL_FOR_ARG30, \
        ARM64_SYSREG_CALL_FOR_ARG29, \
        ARM64_SYSREG_CALL_FOR_ARG28, \
        ARM64_SYSREG_CALL_FOR_ARG27, \
        ARM64_SYSREG_CALL_FOR_ARG26, \
        ARM64_SYSREG_CALL_FOR_ARG25, \
        ARM64_SYSREG_CALL_FOR_ARG24, \
        ARM64_SYSREG_CALL_FOR_ARG23, \
        ARM64_SYSREG_CALL_FOR_ARG22, \
        ARM64_SYSREG_CALL_FOR_ARG21, \
        ARM64_SYSREG_CALL_FOR_ARG20, \
        ARM64_SYSREG_CALL_FOR_ARG19, \
        ARM64_SYSREG_CALL_FOR_ARG18, \
        ARM64_SYSREG_CALL_FOR_ARG17, \
        ARM64_SYSREG_CALL_FOR_ARG16, \
        ARM64_SYSREG_CALL_FOR_ARG15, \
        ARM64_SYSREG_CALL_FOR_ARG14, \
        ARM64_SYSREG_CALL_FOR_ARG13, \
        ARM64_SYSREG_CALL_FOR_ARG12, \
        ARM64_SYSREG_CALL_FOR_ARG11, \
        ARM64_SYSREG_CALL_FOR_ARG10, \
        ARM64_SYSREG_CALL_FOR_ARG9, \
        ARM64_SYSREG_CALL_FOR_ARG8, \
        ARM64_SYSREG_CALL_FOR_ARG7, \
        ARM64_SYSREG_CALL_FOR_ARG6, \
        ARM64_SYSREG_CALL_FOR_ARG5, \
        ARM64_SYSREG_CALL_FOR_ARG4, \
        ARM64_SYSREG_CALL_FOR_ARG3, \
        ARM64_SYSREG_CALL_FOR_ARG2, \
        ARM64_SYSREG_CALL_FOR_ARG1, \
        ARM64_SYSREG_CALL_FOR_ARG0, \
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


#ifndef H_HFGWTR_EL2
#define H_HFGWTR_EL2



union hfgwtr_el2
{
    u64 _;
    __extension__ struct {
        u64 afsr0_el1 : 1;
        u64 afsr1_el1 : 1;
        u64 res0_2 : 1;
        u64 amair_el1 : 1;
        u64 apdakey : 1;
        u64 apdbkey : 1;
        u64 apgakey : 1;
        u64 apiakey : 1;
        u64 apibkey : 1;
        u64 res0_10_9 : 2;
        u64 contextidr_el1 : 1;
        u64 cpacr_el1 : 1;
        u64 csselr_el1 : 1;
        u64 res0_15_14 : 2;
        u64 esr_el1 : 1;
        u64 far_el1 : 1;
        u64 res0_18 : 1;
        u64 lorc_el1 : 1;
        u64 lorea_el1 : 1;
        u64 res0_21 : 1;
        u64 lorn_el1 : 1;
        u64 lorsa_el1 : 1;
        u64 mair_el1 : 1;
        u64 res0_26_25 : 2;
        u64 par_el1 : 1;
        u64 res0_28 : 1;
        u64 sctlr_el1 : 1;
        u64 scxtnum_el1 : 1;
        u64 scxtnum_el0 : 1;
        u64 tcr_el1 : 1;
        u64 tpidr_el1 : 1;
        u64 tpidrro_el0 : 1;
        u64 tpidr_el0 : 1;
        u64 ttbr0_el1 : 1;
        u64 ttbr1_el1 : 1;
        u64 vbar_el1 : 1;
        u64 icc_igrpenn_el1 : 1;
        u64 res0_40 : 1;
        u64 errselr_el1 : 1;
        u64 res0_42 : 1;
        u64 erxctlr_el1 : 1;
        u64 erxstatus_el1 : 1;
        u64 erxmiscn_el1 : 1;
        u64 res0_46 : 1;
        u64 erxpfgctl_el1 : 1;
        u64 erxpfgcdn_el1 : 1;
        u64 erxaddr_el1 : 1;
        u64 res0_63_50 : 14;
    };
};



static const union hfgwtr_el2 HFGWTR_EL2_SAFEVAL =
{0
};



static inline union hfgwtr_el2 read_hfgwtr_el2( void )
{
    union hfgwtr_el2 tmp;
    __asm(
        "MRS %0, s3_4_c1_c1_5"
        : "=r" (tmp._)
    );
    return tmp;
}



static inline void unsafe_write_hfgwtr_el2( union hfgwtr_el2 val )
{
    __asm(
        "MSR s3_4_c1_c1_5, %0"
        : /**/ : "r" (val._)
    );
}



#define safe_write_hfgwtr_el2( ... ) \
    do \
    { \
        union hfgwtr_el2 tmp = HFGWTR_EL2_SAFEVAL; \
        ARM64_SYSREG_CALL_FOR_EACH(ARM64_SYSREG_SET, __VA_ARGS__) \
        unsafe_write_hfgwtr_el2(tmp); \
    } while (0)



#define read_modify_write_hfgwtr_el2( ... ) \
    do \
    { \
        union hfgwtr_el2 tmp = read_hfgwtr_el2(); \
        ARM64_SYSREG_CALL_FOR_EACH(ARM64_SYSREG_SET, __VA_ARGS__) \
        unsafe_write_hfgwtr_el2(tmp); \
    } while (0)


/* H_HFGWTR_EL2 */
#endif
