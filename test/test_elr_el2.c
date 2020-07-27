

#include "sysreg/elr_el2.h"


u64 test_read_elr_el2( void )
{
    return read_elr_el2().Return_address;
}


void test_unsafe_write_elr_el2( void )
{
    unsafe_write_elr_el2((union elr_el2){ .Return_address=1 });
}


void test_safe_write_elr_el2( void )
{
    safe_write_elr_el2( .Return_address=1 );
}


void test_read_modify_write_elr_el2( void )
{
    read_modify_write_elr_el2( .Return_address=1 );
}

