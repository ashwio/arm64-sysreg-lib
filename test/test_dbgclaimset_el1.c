

#include "sysreg/dbgclaimset_el1.h"


u64 test_read_dbgclaimset_el1( void )
{
    return read_dbgclaimset_el1().claim;
}


void test_unsafe_write_dbgclaimset_el1( void )
{
    unsafe_write_dbgclaimset_el1((union dbgclaimset_el1){ .claim=1 });
}


void test_safe_write_dbgclaimset_el1( void )
{
    safe_write_dbgclaimset_el1( .claim=1 );
}


void test_read_modify_write_dbgclaimset_el1( void )
{
    read_modify_write_dbgclaimset_el1( .claim=1 );
}

