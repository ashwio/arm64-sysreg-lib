

#include "sysreg/osdtrtx_el1.h"


u64 test_read_osdtrtx_el1( void )
{
    return read_osdtrtx_el1().Return_DTRTX_without_side_effect;
}


void test_unsafe_write_osdtrtx_el1( void )
{
    unsafe_write_osdtrtx_el1((union osdtrtx_el1){ .Return_DTRTX_without_side_effect=1 });
}


void test_safe_write_osdtrtx_el1( void )
{
    safe_write_osdtrtx_el1( .Return_DTRTX_without_side_effect=1 );
}


void test_read_modify_write_osdtrtx_el1( void )
{
    read_modify_write_osdtrtx_el1( .Return_DTRTX_without_side_effect=1 );
}

