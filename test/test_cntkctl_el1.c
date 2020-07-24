

#include "sysreg/cntkctl_el1.h"


u64 test_read_cntkctl_el1( void )
{
    return read_cntkctl_el1().el0pcten;
}


void test_unsafe_write_cntkctl_el1( void )
{
    unsafe_write_cntkctl_el1((union cntkctl_el1){ .el0pcten=1 });
}


void test_safe_write_cntkctl_el1( void )
{
    safe_write_cntkctl_el1( .el0pcten=1 );
}


void test_read_modify_write_cntkctl_el1( void )
{
    read_modify_write_cntkctl_el1( .el0pcten=1 );
}

