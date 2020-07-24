

#include "sysreg/pmccfiltr_el0.h"


u64 test_read_pmccfiltr_el0( void )
{
    return read_pmccfiltr_el0().res0_23_0;
}


void test_unsafe_write_pmccfiltr_el0( void )
{
    unsafe_write_pmccfiltr_el0((union pmccfiltr_el0){ .res0_23_0=1 });
}


void test_safe_write_pmccfiltr_el0( void )
{
    safe_write_pmccfiltr_el0( .res0_23_0=1 );
}


void test_read_modify_write_pmccfiltr_el0( void )
{
    read_modify_write_pmccfiltr_el0( .res0_23_0=1 );
}

