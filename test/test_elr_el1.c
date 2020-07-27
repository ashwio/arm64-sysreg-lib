

#include "sysreg/elr_el1.h"


u64 test_read_elr_el1( void )
{
    return read_elr_el1().Return_address;
}


void test_unsafe_write_elr_el1( void )
{
    unsafe_write_elr_el1((union elr_el1){ .Return_address=1 });
}


void test_safe_write_elr_el1( void )
{
    safe_write_elr_el1( .Return_address=1 );
}


void test_read_modify_write_elr_el1( void )
{
    read_modify_write_elr_el1( .Return_address=1 );
}

