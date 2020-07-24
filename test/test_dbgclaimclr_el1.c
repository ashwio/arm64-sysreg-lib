

#include "sysreg/dbgclaimclr_el1.h"


u64 test_read_dbgclaimclr_el1( void )
{
    return read_dbgclaimclr_el1().claim;
}


void test_unsafe_write_dbgclaimclr_el1( void )
{
    unsafe_write_dbgclaimclr_el1((union dbgclaimclr_el1){ .claim=1 });
}


void test_safe_write_dbgclaimclr_el1( void )
{
    safe_write_dbgclaimclr_el1( .claim=1 );
}


void test_read_modify_write_dbgclaimclr_el1( void )
{
    read_modify_write_dbgclaimclr_el1( .claim=1 );
}

