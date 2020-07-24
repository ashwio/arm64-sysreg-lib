

#include "sysreg/tcr_el3.h"


u64 test_read_tcr_el3( void )
{
    return read_tcr_el3().t0sz;
}


void test_unsafe_write_tcr_el3( void )
{
    unsafe_write_tcr_el3((union tcr_el3){ .t0sz=1 });
}


void test_safe_write_tcr_el3( void )
{
    safe_write_tcr_el3( .t0sz=1 );
}


void test_read_modify_write_tcr_el3( void )
{
    read_modify_write_tcr_el3( .t0sz=1 );
}

