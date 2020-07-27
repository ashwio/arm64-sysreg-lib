

#include "sysreg/vstcr_el2.h"


u64 test_read_vstcr_el2( void )
{
    return read_vstcr_el2().t0sz;
}


void test_unsafe_write_vstcr_el2( void )
{
    unsafe_write_vstcr_el2((union vstcr_el2){ .t0sz=1 });
}


void test_safe_write_vstcr_el2( void )
{
    safe_write_vstcr_el2( .t0sz=1 );
}


void test_read_modify_write_vstcr_el2( void )
{
    read_modify_write_vstcr_el2( .t0sz=1 );
}

