

#include "sysreg/mpamhcr_el2.h"


u64 test_read_mpamhcr_el2( void )
{
    return read_mpamhcr_el2().el0_vpmen;
}


void test_unsafe_write_mpamhcr_el2( void )
{
    unsafe_write_mpamhcr_el2((union mpamhcr_el2){ .el0_vpmen=1 });
}


void test_safe_write_mpamhcr_el2( void )
{
    safe_write_mpamhcr_el2( .el0_vpmen=1 );
}


void test_read_modify_write_mpamhcr_el2( void )
{
    read_modify_write_mpamhcr_el2( .el0_vpmen=1 );
}

