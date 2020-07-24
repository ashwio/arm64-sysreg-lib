

#include "sysreg/mdcr_el2.h"


u64 test_read_mdcr_el2( void )
{
    return read_mdcr_el2().hpmn;
}


void test_unsafe_write_mdcr_el2( void )
{
    unsafe_write_mdcr_el2((union mdcr_el2){ .hpmn=1 });
}


void test_safe_write_mdcr_el2( void )
{
    safe_write_mdcr_el2( .hpmn=1 );
}


void test_read_modify_write_mdcr_el2( void )
{
    read_modify_write_mdcr_el2( .hpmn=1 );
}

