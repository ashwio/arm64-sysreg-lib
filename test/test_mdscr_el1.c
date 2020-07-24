

#include "sysreg/mdscr_el1.h"


u64 test_read_mdscr_el1( void )
{
    return read_mdscr_el1().ss;
}


void test_unsafe_write_mdscr_el1( void )
{
    unsafe_write_mdscr_el1((union mdscr_el1){ .ss=1 });
}


void test_safe_write_mdscr_el1( void )
{
    safe_write_mdscr_el1( .ss=1 );
}


void test_read_modify_write_mdscr_el1( void )
{
    read_modify_write_mdscr_el1( .ss=1 );
}

