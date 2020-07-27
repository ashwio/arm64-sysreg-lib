

#include "sysreg/sp_el0.h"


u64 test_read_sp_el0( void )
{
    return read_sp_el0().Stack_pointer;
}


void test_unsafe_write_sp_el0( void )
{
    unsafe_write_sp_el0((union sp_el0){ .Stack_pointer=1 });
}


void test_safe_write_sp_el0( void )
{
    safe_write_sp_el0( .Stack_pointer=1 );
}


void test_read_modify_write_sp_el0( void )
{
    read_modify_write_sp_el0( .Stack_pointer=1 );
}

