

#include "sysreg/vbar_el1.h"


u64 test_read_vbar_el1( void )
{
    return read_vbar_el1().res0_10_0;
}


void test_unsafe_write_vbar_el1( void )
{
    unsafe_write_vbar_el1((union vbar_el1){ .res0_10_0=1 });
}


void test_safe_write_vbar_el1( void )
{
    safe_write_vbar_el1( .res0_10_0=1 );
}


void test_read_modify_write_vbar_el1( void )
{
    read_modify_write_vbar_el1( .res0_10_0=1 );
}

