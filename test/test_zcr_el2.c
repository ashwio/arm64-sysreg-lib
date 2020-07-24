

#include "sysreg/zcr_el2.h"


u64 test_read_zcr_el2( void )
{
    return read_zcr_el2().len;
}


void test_unsafe_write_zcr_el2( void )
{
    unsafe_write_zcr_el2((union zcr_el2){ .len=1 });
}


void test_safe_write_zcr_el2( void )
{
    safe_write_zcr_el2( .len=1 );
}


void test_read_modify_write_zcr_el2( void )
{
    read_modify_write_zcr_el2( .len=1 );
}

