

#include "sysreg/lorsa_el1.h"


u64 test_read_lorsa_el1( void )
{
    return read_lorsa_el1().valid;
}


void test_unsafe_write_lorsa_el1( void )
{
    unsafe_write_lorsa_el1((union lorsa_el1){ .valid=1 });
}


void test_safe_write_lorsa_el1( void )
{
    safe_write_lorsa_el1( .valid=1 );
}


void test_read_modify_write_lorsa_el1( void )
{
    read_modify_write_lorsa_el1( .valid=1 );
}

