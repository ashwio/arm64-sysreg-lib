

#include "sysreg/pan.h"


u64 test_read_pan( void )
{
    return read_pan().res0_21_0;
}


void test_unsafe_write_pan( void )
{
    unsafe_write_pan((union pan){ .res0_21_0=1 });
}


void test_safe_write_pan( void )
{
    safe_write_pan( .res0_21_0=1 );
}


void test_read_modify_write_pan( void )
{
    read_modify_write_pan( .res0_21_0=1 );
}

