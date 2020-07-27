

#include "sysreg/sp_el2.h"


u64 test_read_sp_el2( void )
{
    return read_sp_el2().Stack_pointer;
}


void test_unsafe_write_sp_el2( void )
{
    unsafe_write_sp_el2((union sp_el2){ .Stack_pointer=1 });
}


void test_safe_write_sp_el2( void )
{
    safe_write_sp_el2( .Stack_pointer=1 );
}


void test_read_modify_write_sp_el2( void )
{
    read_modify_write_sp_el2( .Stack_pointer=1 );
}

