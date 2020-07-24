

#include "sysreg/daif.h"


u64 test_read_daif( void )
{
    return read_daif().res0_5_0;
}


void test_unsafe_write_daif( void )
{
    unsafe_write_daif((union daif){ .res0_5_0=1 });
}


void test_safe_write_daif( void )
{
    safe_write_daif( .res0_5_0=1 );
}


void test_read_modify_write_daif( void )
{
    read_modify_write_daif( .res0_5_0=1 );
}

