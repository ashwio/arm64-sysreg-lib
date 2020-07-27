

#include "sysreg/tpidrro_el0.h"


u64 test_read_tpidrro_el0( void )
{
    return read_tpidrro_el0().Thread_ID;
}


void test_unsafe_write_tpidrro_el0( void )
{
    unsafe_write_tpidrro_el0((union tpidrro_el0){ .Thread_ID=1 });
}


void test_safe_write_tpidrro_el0( void )
{
    safe_write_tpidrro_el0( .Thread_ID=1 );
}


void test_read_modify_write_tpidrro_el0( void )
{
    read_modify_write_tpidrro_el0( .Thread_ID=1 );
}

