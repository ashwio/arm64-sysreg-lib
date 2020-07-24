

#include "sysreg/ssbs.h"


u64 test_read_ssbs( void )
{
    return read_ssbs().res0_11_0;
}


void test_unsafe_write_ssbs( void )
{
    unsafe_write_ssbs((union ssbs){ .res0_11_0=1 });
}


void test_safe_write_ssbs( void )
{
    safe_write_ssbs( .res0_11_0=1 );
}


void test_read_modify_write_ssbs( void )
{
    read_modify_write_ssbs( .res0_11_0=1 );
}

