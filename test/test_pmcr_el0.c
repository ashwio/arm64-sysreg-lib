

#include "sysreg/pmcr_el0.h"


u64 test_read_pmcr_el0( void )
{
    return read_pmcr_el0().e;
}


void test_unsafe_write_pmcr_el0( void )
{
    unsafe_write_pmcr_el0((union pmcr_el0){ .e=1 });
}


void test_safe_write_pmcr_el0( void )
{
    safe_write_pmcr_el0( .e=1 );
}


void test_read_modify_write_pmcr_el0( void )
{
    read_modify_write_pmcr_el0( .e=1 );
}

