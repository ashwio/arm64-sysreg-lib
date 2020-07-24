

#include "sysreg/nzcv.h"


u64 test_read_nzcv( void )
{
    return read_nzcv().res0_27_0;
}


void test_unsafe_write_nzcv( void )
{
    unsafe_write_nzcv((union nzcv){ .res0_27_0=1 });
}


void test_safe_write_nzcv( void )
{
    safe_write_nzcv( .res0_27_0=1 );
}


void test_read_modify_write_nzcv( void )
{
    read_modify_write_nzcv( .res0_27_0=1 );
}

