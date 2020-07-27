

#include "sysreg/vtcr_el2.h"


u64 test_read_vtcr_el2( void )
{
    return read_vtcr_el2().t0sz;
}


void test_unsafe_write_vtcr_el2( void )
{
    unsafe_write_vtcr_el2((union vtcr_el2){ .t0sz=1 });
}


void test_safe_write_vtcr_el2( void )
{
    safe_write_vtcr_el2( .t0sz=1 );
}


void test_read_modify_write_vtcr_el2( void )
{
    read_modify_write_vtcr_el2( .t0sz=1 );
}

