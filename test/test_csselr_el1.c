

#include "sysreg/csselr_el1.h"


u64 test_read_csselr_el1( void )
{
    return read_csselr_el1().ind;
}


void test_unsafe_write_csselr_el1( void )
{
    unsafe_write_csselr_el1((union csselr_el1){ .ind=1 });
}


void test_safe_write_csselr_el1( void )
{
    safe_write_csselr_el1( .ind=1 );
}


void test_read_modify_write_csselr_el1( void )
{
    read_modify_write_csselr_el1( .ind=1 );
}

