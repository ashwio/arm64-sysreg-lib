

#include "sysreg/vbar_el3.h"


u64 test_read_vbar_el3( void )
{
    return read_vbar_el3().res0_10_0;
}


void test_unsafe_write_vbar_el3( void )
{
    unsafe_write_vbar_el3((union vbar_el3){ .res0_10_0=1 });
}


void test_safe_write_vbar_el3( void )
{
    safe_write_vbar_el3( .res0_10_0=1 );
}


void test_read_modify_write_vbar_el3( void )
{
    read_modify_write_vbar_el3( .res0_10_0=1 );
}

