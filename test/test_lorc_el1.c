

#include "sysreg/lorc_el1.h"


u64 test_read_lorc_el1( void )
{
    return read_lorc_el1().en;
}


void test_unsafe_write_lorc_el1( void )
{
    unsafe_write_lorc_el1((union lorc_el1){ .en=1 });
}


void test_safe_write_lorc_el1( void )
{
    safe_write_lorc_el1( .en=1 );
}


void test_read_modify_write_lorc_el1( void )
{
    read_modify_write_lorc_el1( .en=1 );
}

