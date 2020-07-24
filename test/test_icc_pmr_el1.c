

#include "sysreg/icc_pmr_el1.h"


u64 test_read_icc_pmr_el1( void )
{
    return read_icc_pmr_el1().priority;
}


void test_unsafe_write_icc_pmr_el1( void )
{
    unsafe_write_icc_pmr_el1((union icc_pmr_el1){ .priority=1 });
}


void test_safe_write_icc_pmr_el1( void )
{
    safe_write_icc_pmr_el1( .priority=1 );
}


void test_read_modify_write_icc_pmr_el1( void )
{
    read_modify_write_icc_pmr_el1( .priority=1 );
}

