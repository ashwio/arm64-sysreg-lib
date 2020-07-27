

#include "sysreg/sp_el1.h"


u64 test_read_sp_el1( void )
{
    return read_sp_el1().Stack_pointer;
}


void test_unsafe_write_sp_el1( void )
{
    unsafe_write_sp_el1((union sp_el1){ .Stack_pointer=1 });
}


void test_safe_write_sp_el1( void )
{
    safe_write_sp_el1( .Stack_pointer=1 );
}


void test_read_modify_write_sp_el1( void )
{
    read_modify_write_sp_el1( .Stack_pointer=1 );
}

