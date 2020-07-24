

#include "sysreg/cntp_ctl_el0.h"


u64 test_read_cntp_ctl_el0( void )
{
    return read_cntp_ctl_el0().enable;
}


void test_unsafe_write_cntp_ctl_el0( void )
{
    unsafe_write_cntp_ctl_el0((union cntp_ctl_el0){ .enable=1 });
}


void test_safe_write_cntp_ctl_el0( void )
{
    safe_write_cntp_ctl_el0( .enable=1 );
}


void test_read_modify_write_cntp_ctl_el0( void )
{
    read_modify_write_cntp_ctl_el0( .enable=1 );
}

