

#include "sysreg/osdtrrx_el1.h"


u64 test_read_osdtrrx_el1( void )
{
    return read_osdtrrx_el1().Update_DTRRX_without_side-effect;
}


void test_unsafe_write_osdtrrx_el1( void )
{
    unsafe_write_osdtrrx_el1((union osdtrrx_el1){ .Update_DTRRX_without_side-effect=1 });
}


void test_safe_write_osdtrrx_el1( void )
{
    safe_write_osdtrrx_el1( .Update_DTRRX_without_side-effect=1 );
}


void test_read_modify_write_osdtrrx_el1( void )
{
    read_modify_write_osdtrrx_el1( .Update_DTRRX_without_side-effect=1 );
}

