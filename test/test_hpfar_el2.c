

#include "sysreg/hpfar_el2.h"


u64 test_read_hpfar_el2( void )
{
    return read_hpfar_el2().res0_3_0;
}


void test_unsafe_write_hpfar_el2( void )
{
    unsafe_write_hpfar_el2((union hpfar_el2){ .res0_3_0=1 });
}


void test_safe_write_hpfar_el2( void )
{
    safe_write_hpfar_el2( .res0_3_0=1 );
}


void test_read_modify_write_hpfar_el2( void )
{
    read_modify_write_hpfar_el2( .res0_3_0=1 );
}

