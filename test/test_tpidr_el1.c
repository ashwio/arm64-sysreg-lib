

#include "sysreg/tpidr_el1.h"


u64 test_read_tpidr_el1( void )
{
    return read_tpidr_el1().Thread_ID;
}


void test_unsafe_write_tpidr_el1( void )
{
    unsafe_write_tpidr_el1((union tpidr_el1){ .Thread_ID=1 });
}


void test_safe_write_tpidr_el1( void )
{
    safe_write_tpidr_el1( .Thread_ID=1 );
}


void test_read_modify_write_tpidr_el1( void )
{
    read_modify_write_tpidr_el1( .Thread_ID=1 );
}

