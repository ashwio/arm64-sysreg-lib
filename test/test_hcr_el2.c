

#include "sysreg/hcr_el2.h"


u64 test_read_hcr_el2( void )
{
    return read_hcr_el2().vm;
}


void test_unsafe_write_hcr_el2( void )
{
    unsafe_write_hcr_el2((union hcr_el2){ .vm=1 });
}


void test_safe_write_hcr_el2( void )
{
    safe_write_hcr_el2( .vm=1 );
}


void test_read_modify_write_hcr_el2( void )
{
    read_modify_write_hcr_el2( .vm=1 );
}

