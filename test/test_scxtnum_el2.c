

#include "sysreg/scxtnum_el2.h"


u64 test_read_scxtnum_el2( void )
{
    return read_scxtnum_el2().Software_Context_Number;
}


void test_unsafe_write_scxtnum_el2( void )
{
    unsafe_write_scxtnum_el2((union scxtnum_el2){ .Software_Context_Number=1 });
}


void test_safe_write_scxtnum_el2( void )
{
    safe_write_scxtnum_el2( .Software_Context_Number=1 );
}


void test_read_modify_write_scxtnum_el2( void )
{
    read_modify_write_scxtnum_el2( .Software_Context_Number=1 );
}

