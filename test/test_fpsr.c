

#include "sysreg/fpsr.h"


u64 test_read_fpsr( void )
{
    return read_fpsr().ioc;
}


void test_unsafe_write_fpsr( void )
{
    unsafe_write_fpsr((union fpsr){ .ioc=1 });
}


void test_safe_write_fpsr( void )
{
    safe_write_fpsr( .ioc=1 );
}


void test_read_modify_write_fpsr( void )
{
    read_modify_write_fpsr( .ioc=1 );
}

