

#include "sysreg/errselr_el1.h"


u64 test_read_errselr_el1( void )
{
    return read_errselr_el1().sel;
}


void test_unsafe_write_errselr_el1( void )
{
    unsafe_write_errselr_el1((union errselr_el1){ .sel=1 });
}


void test_safe_write_errselr_el1( void )
{
    safe_write_errselr_el1( .sel=1 );
}


void test_read_modify_write_errselr_el1( void )
{
    read_modify_write_errselr_el1( .sel=1 );
}

