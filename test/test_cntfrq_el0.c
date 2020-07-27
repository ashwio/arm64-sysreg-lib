

#include "sysreg/cntfrq_el0.h"


u64 test_read_cntfrq_el0( void )
{
    return read_cntfrq_el0().Clock_frequency;
}


void test_unsafe_write_cntfrq_el0( void )
{
    unsafe_write_cntfrq_el0((union cntfrq_el0){ .Clock_frequency=1 });
}


void test_safe_write_cntfrq_el0( void )
{
    safe_write_cntfrq_el0( .Clock_frequency=1 );
}


void test_read_modify_write_cntfrq_el0( void )
{
    read_modify_write_cntfrq_el0( .Clock_frequency=1 );
}

