

#include "sysreg/tcr_el1.h"


u64 test_read_tcr_el1( void )
{
    return read_tcr_el1().t0sz;
}


void test_unsafe_write_tcr_el1( void )
{
    unsafe_write_tcr_el1((union tcr_el1){ .t0sz=1 });
}


void test_safe_write_tcr_el1( void )
{
    safe_write_tcr_el1( .t0sz=1 );
}


void test_read_modify_write_tcr_el1( void )
{
    read_modify_write_tcr_el1( .t0sz=1 );
}

