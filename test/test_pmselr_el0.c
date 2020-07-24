

#include "sysreg/pmselr_el0.h"


u64 test_read_pmselr_el0( void )
{
    return read_pmselr_el0().sel;
}


void test_unsafe_write_pmselr_el0( void )
{
    unsafe_write_pmselr_el0((union pmselr_el0){ .sel=1 });
}


void test_safe_write_pmselr_el0( void )
{
    safe_write_pmselr_el0( .sel=1 );
}


void test_read_modify_write_pmselr_el0( void )
{
    read_modify_write_pmselr_el0( .sel=1 );
}

