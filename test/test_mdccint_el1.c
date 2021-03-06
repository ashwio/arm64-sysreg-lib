

#include "sysreg/mdccint_el1.h"


u64 test_read_mdccint_el1( void )
{
    return read_mdccint_el1().res0_28_0;
}


void test_unsafe_write_mdccint_el1( void )
{
    unsafe_write_mdccint_el1((union mdccint_el1){ .res0_28_0=1 });
}


void test_safe_write_mdccint_el1( void )
{
    safe_write_mdccint_el1( .res0_28_0=1 );
}


void test_read_modify_write_mdccint_el1( void )
{
    read_modify_write_mdccint_el1( .res0_28_0=1 );
}

