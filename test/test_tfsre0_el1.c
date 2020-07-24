

#include "sysreg/tfsre0_el1.h"


u64 test_read_tfsre0_el1( void )
{
    return read_tfsre0_el1().tf0;
}


void test_unsafe_write_tfsre0_el1( void )
{
    unsafe_write_tfsre0_el1((union tfsre0_el1){ .tf0=1 });
}


void test_safe_write_tfsre0_el1( void )
{
    safe_write_tfsre0_el1( .tf0=1 );
}


void test_read_modify_write_tfsre0_el1( void )
{
    read_modify_write_tfsre0_el1( .tf0=1 );
}

