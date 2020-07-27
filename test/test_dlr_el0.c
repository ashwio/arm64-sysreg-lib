

#include "sysreg/dlr_el0.h"


u64 test_read_dlr_el0( void )
{
    return read_dlr_el0().Restart_address;
}


void test_unsafe_write_dlr_el0( void )
{
    unsafe_write_dlr_el0((union dlr_el0){ .Restart_address=1 });
}


void test_safe_write_dlr_el0( void )
{
    safe_write_dlr_el0( .Restart_address=1 );
}


void test_read_modify_write_dlr_el0( void )
{
    read_modify_write_dlr_el0( .Restart_address=1 );
}

