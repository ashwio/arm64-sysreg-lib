

#include "sysreg/scxtnum_el3.h"


u64 test_read_scxtnum_el3( void )
{
    return read_scxtnum_el3().Software_Context_Number;
}


void test_unsafe_write_scxtnum_el3( void )
{
    unsafe_write_scxtnum_el3((union scxtnum_el3){ .Software_Context_Number=1 });
}


void test_safe_write_scxtnum_el3( void )
{
    safe_write_scxtnum_el3( .Software_Context_Number=1 );
}


void test_read_modify_write_scxtnum_el3( void )
{
    read_modify_write_scxtnum_el3( .Software_Context_Number=1 );
}

