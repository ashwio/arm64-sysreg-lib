

#include "sysreg/hfgrtr_el2.h"


u64 test_read_hfgrtr_el2( void )
{
    return read_hfgrtr_el2().afsr0_el1;
}


void test_unsafe_write_hfgrtr_el2( void )
{
    unsafe_write_hfgrtr_el2((union hfgrtr_el2){ .afsr0_el1=1 });
}


void test_safe_write_hfgrtr_el2( void )
{
    safe_write_hfgrtr_el2( .afsr0_el1=1 );
}


void test_read_modify_write_hfgrtr_el2( void )
{
    read_modify_write_hfgrtr_el2( .afsr0_el1=1 );
}

