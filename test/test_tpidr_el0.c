

#include "sysreg/tpidr_el0.h"


u64 test_read_tpidr_el0( void )
{
    return read_tpidr_el0().Thread_ID;
}


void test_unsafe_write_tpidr_el0( void )
{
    unsafe_write_tpidr_el0((union tpidr_el0){ .Thread_ID=1 });
}


void test_safe_write_tpidr_el0( void )
{
    safe_write_tpidr_el0( .Thread_ID=1 );
}


void test_read_modify_write_tpidr_el0( void )
{
    read_modify_write_tpidr_el0( .Thread_ID=1 );
}

