

#include "sysreg/amcr_el0.h"


u64 test_read_amcr_el0( void )
{
    return read_amcr_el0().res0_9_0;
}


void test_unsafe_write_amcr_el0( void )
{
    unsafe_write_amcr_el0((union amcr_el0){ .res0_9_0=1 });
}


void test_safe_write_amcr_el0( void )
{
    safe_write_amcr_el0( .res0_9_0=1 );
}


void test_read_modify_write_amcr_el0( void )
{
    read_modify_write_amcr_el0( .res0_9_0=1 );
}

