

#include "sysreg/rmr_el1.h"


u64 test_read_rmr_el1( void )
{
    return read_rmr_el1().aa64;
}


void test_unsafe_write_rmr_el1( void )
{
    unsafe_write_rmr_el1((union rmr_el1){ .aa64=1 });
}


void test_safe_write_rmr_el1( void )
{
    safe_write_rmr_el1( .aa64=1 );
}


void test_read_modify_write_rmr_el1( void )
{
    read_modify_write_rmr_el1( .aa64=1 );
}

