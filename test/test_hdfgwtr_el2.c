

#include "sysreg/hdfgwtr_el2.h"


u64 test_read_hdfgwtr_el2( void )
{
    return read_hdfgwtr_el2().dbgbcrn_el1;
}


void test_unsafe_write_hdfgwtr_el2( void )
{
    unsafe_write_hdfgwtr_el2((union hdfgwtr_el2){ .dbgbcrn_el1=1 });
}


void test_safe_write_hdfgwtr_el2( void )
{
    safe_write_hdfgwtr_el2( .dbgbcrn_el1=1 );
}


void test_read_modify_write_hdfgwtr_el2( void )
{
    read_modify_write_hdfgwtr_el2( .dbgbcrn_el1=1 );
}

