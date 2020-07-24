

#include "sysreg/dit.h"


u64 test_read_dit( void )
{
    return read_dit().res0_23_0;
}


void test_unsafe_write_dit( void )
{
    unsafe_write_dit((union dit){ .res0_23_0=1 });
}


void test_safe_write_dit( void )
{
    safe_write_dit( .res0_23_0=1 );
}


void test_read_modify_write_dit( void )
{
    read_modify_write_dit( .res0_23_0=1 );
}

