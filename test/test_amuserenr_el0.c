

#include "sysreg/amuserenr_el0.h"


u64 test_read_amuserenr_el0( void )
{
    return read_amuserenr_el0().en;
}


void test_unsafe_write_amuserenr_el0( void )
{
    unsafe_write_amuserenr_el0((union amuserenr_el0){ .en=1 });
}


void test_safe_write_amuserenr_el0( void )
{
    safe_write_amuserenr_el0( .en=1 );
}


void test_read_modify_write_amuserenr_el0( void )
{
    read_modify_write_amuserenr_el0( .en=1 );
}

