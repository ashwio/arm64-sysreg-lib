

#include "sysreg/fpcr.h"


u64 test_read_fpcr( void )
{
    return read_fpcr().res0_7_0;
}


void test_unsafe_write_fpcr( void )
{
    unsafe_write_fpcr((union fpcr){ .res0_7_0=1 });
}


void test_safe_write_fpcr( void )
{
    safe_write_fpcr( .res0_7_0=1 );
}


void test_read_modify_write_fpcr( void )
{
    read_modify_write_fpcr( .res0_7_0=1 );
}

