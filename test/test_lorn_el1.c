

#include "sysreg/lorn_el1.h"


u64 test_read_lorn_el1( void )
{
    return read_lorn_el1().num;
}


void test_unsafe_write_lorn_el1( void )
{
    unsafe_write_lorn_el1((union lorn_el1){ .num=1 });
}


void test_safe_write_lorn_el1( void )
{
    safe_write_lorn_el1( .num=1 );
}


void test_read_modify_write_lorn_el1( void )
{
    read_modify_write_lorn_el1( .num=1 );
}

