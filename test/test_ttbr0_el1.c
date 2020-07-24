

#include "sysreg/ttbr0_el1.h"


u64 test_read_ttbr0_el1( void )
{
    return read_ttbr0_el1().cnp;
}


void test_unsafe_write_ttbr0_el1( void )
{
    unsafe_write_ttbr0_el1((union ttbr0_el1){ .cnp=1 });
}


void test_safe_write_ttbr0_el1( void )
{
    safe_write_ttbr0_el1( .cnp=1 );
}


void test_read_modify_write_ttbr0_el1( void )
{
    read_modify_write_ttbr0_el1( .cnp=1 );
}

