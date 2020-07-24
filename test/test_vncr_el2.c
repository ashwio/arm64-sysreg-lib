

#include "sysreg/vncr_el2.h"


u64 test_read_vncr_el2( void )
{
    return read_vncr_el2().res0_11_0;
}


void test_unsafe_write_vncr_el2( void )
{
    unsafe_write_vncr_el2((union vncr_el2){ .res0_11_0=1 });
}


void test_safe_write_vncr_el2( void )
{
    safe_write_vncr_el2( .res0_11_0=1 );
}


void test_read_modify_write_vncr_el2( void )
{
    read_modify_write_vncr_el2( .res0_11_0=1 );
}

