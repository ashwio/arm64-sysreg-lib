

#include "sysreg/elr_el3.h"


u64 test_read_elr_el3( void )
{
    return read_elr_el3().Return_address;
}


void test_unsafe_write_elr_el3( void )
{
    unsafe_write_elr_el3((union elr_el3){ .Return_address=1 });
}


void test_safe_write_elr_el3( void )
{
    safe_write_elr_el3( .Return_address=1 );
}


void test_read_modify_write_elr_el3( void )
{
    read_modify_write_elr_el3( .Return_address=1 );
}

