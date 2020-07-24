

#include "sysreg/pmsirr_el1.h"


u64 test_read_pmsirr_el1( void )
{
    return read_pmsirr_el1().rnd;
}


void test_unsafe_write_pmsirr_el1( void )
{
    unsafe_write_pmsirr_el1((union pmsirr_el1){ .rnd=1 });
}


void test_safe_write_pmsirr_el1( void )
{
    safe_write_pmsirr_el1( .rnd=1 );
}


void test_read_modify_write_pmsirr_el1( void )
{
    read_modify_write_pmsirr_el1( .rnd=1 );
}

