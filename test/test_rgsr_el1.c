

#include "sysreg/rgsr_el1.h"


u64 test_read_rgsr_el1( void )
{
    return read_rgsr_el1().tag;
}


void test_unsafe_write_rgsr_el1( void )
{
    unsafe_write_rgsr_el1((union rgsr_el1){ .tag=1 });
}


void test_safe_write_rgsr_el1( void )
{
    safe_write_rgsr_el1( .tag=1 );
}


void test_read_modify_write_rgsr_el1( void )
{
    read_modify_write_rgsr_el1( .tag=1 );
}

