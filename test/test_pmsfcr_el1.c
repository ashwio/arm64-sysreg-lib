

#include "sysreg/pmsfcr_el1.h"


u64 test_read_pmsfcr_el1( void )
{
    return read_pmsfcr_el1().fe;
}


void test_unsafe_write_pmsfcr_el1( void )
{
    unsafe_write_pmsfcr_el1((union pmsfcr_el1){ .fe=1 });
}


void test_safe_write_pmsfcr_el1( void )
{
    safe_write_pmsfcr_el1( .fe=1 );
}


void test_read_modify_write_pmsfcr_el1( void )
{
    read_modify_write_pmsfcr_el1( .fe=1 );
}

