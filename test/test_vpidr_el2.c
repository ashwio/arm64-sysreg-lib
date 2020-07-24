

#include "sysreg/vpidr_el2.h"


u64 test_read_vpidr_el2( void )
{
    return read_vpidr_el2().revision;
}


void test_unsafe_write_vpidr_el2( void )
{
    unsafe_write_vpidr_el2((union vpidr_el2){ .revision=1 });
}


void test_safe_write_vpidr_el2( void )
{
    safe_write_vpidr_el2( .revision=1 );
}


void test_read_modify_write_vpidr_el2( void )
{
    read_modify_write_vpidr_el2( .revision=1 );
}

