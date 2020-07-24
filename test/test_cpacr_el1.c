

#include "sysreg/cpacr_el1.h"


u64 test_read_cpacr_el1( void )
{
    return read_cpacr_el1().res0_15_0;
}


void test_unsafe_write_cpacr_el1( void )
{
    unsafe_write_cpacr_el1((union cpacr_el1){ .res0_15_0=1 });
}


void test_safe_write_cpacr_el1( void )
{
    safe_write_cpacr_el1( .res0_15_0=1 );
}


void test_read_modify_write_cpacr_el1( void )
{
    read_modify_write_cpacr_el1( .res0_15_0=1 );
}

