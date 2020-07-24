

#include "sysreg/vmpidr_el2.h"


u64 test_read_vmpidr_el2( void )
{
    return read_vmpidr_el2().aff0;
}


void test_unsafe_write_vmpidr_el2( void )
{
    unsafe_write_vmpidr_el2((union vmpidr_el2){ .aff0=1 });
}


void test_safe_write_vmpidr_el2( void )
{
    safe_write_vmpidr_el2( .aff0=1 );
}


void test_read_modify_write_vmpidr_el2( void )
{
    read_modify_write_vmpidr_el2( .aff0=1 );
}

