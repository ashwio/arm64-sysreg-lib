

#include "sysreg/hfgwtr_el2.h"


u64 test_read_hfgwtr_el2( void )
{
    return read_hfgwtr_el2().afsr0_el1;
}


void test_unsafe_write_hfgwtr_el2( void )
{
    unsafe_write_hfgwtr_el2((union hfgwtr_el2){ .afsr0_el1=1 });
}


void test_safe_write_hfgwtr_el2( void )
{
    safe_write_hfgwtr_el2( .afsr0_el1=1 );
}


void test_read_modify_write_hfgwtr_el2( void )
{
    read_modify_write_hfgwtr_el2( .afsr0_el1=1 );
}

