

#include "sysreg/uao.h"


u64 test_read_uao( void )
{
    return read_uao().res0_22_0;
}


void test_unsafe_write_uao( void )
{
    unsafe_write_uao((union uao){ .res0_22_0=1 });
}


void test_safe_write_uao( void )
{
    safe_write_uao( .res0_22_0=1 );
}


void test_read_modify_write_uao( void )
{
    read_modify_write_uao( .res0_22_0=1 );
}

