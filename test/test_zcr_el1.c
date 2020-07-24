

#include "sysreg/zcr_el1.h"


u64 test_read_zcr_el1( void )
{
    return read_zcr_el1().len;
}


void test_unsafe_write_zcr_el1( void )
{
    unsafe_write_zcr_el1((union zcr_el1){ .len=1 });
}


void test_safe_write_zcr_el1( void )
{
    safe_write_zcr_el1( .len=1 );
}


void test_read_modify_write_zcr_el1( void )
{
    read_modify_write_zcr_el1( .len=1 );
}

