

#include "sysreg/zcr_el3.h"


u64 test_read_zcr_el3( void )
{
    return read_zcr_el3().len;
}


void test_unsafe_write_zcr_el3( void )
{
    unsafe_write_zcr_el3((union zcr_el3){ .len=1 });
}


void test_safe_write_zcr_el3( void )
{
    safe_write_zcr_el3( .len=1 );
}


void test_read_modify_write_zcr_el3( void )
{
    read_modify_write_zcr_el3( .len=1 );
}

