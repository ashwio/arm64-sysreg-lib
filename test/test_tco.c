

#include "sysreg/tco.h"


u64 test_read_tco( void )
{
    return read_tco().res0_24_0;
}


void test_unsafe_write_tco( void )
{
    unsafe_write_tco((union tco){ .res0_24_0=1 });
}


void test_safe_write_tco( void )
{
    safe_write_tco( .res0_24_0=1 );
}


void test_read_modify_write_tco( void )
{
    read_modify_write_tco( .res0_24_0=1 );
}

