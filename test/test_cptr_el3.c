

#include "sysreg/cptr_el3.h"


u64 test_read_cptr_el3( void )
{
    return read_cptr_el3().res0_7_0;
}


void test_unsafe_write_cptr_el3( void )
{
    unsafe_write_cptr_el3((union cptr_el3){ .res0_7_0=1 });
}


void test_safe_write_cptr_el3( void )
{
    safe_write_cptr_el3( .res0_7_0=1 );
}


void test_read_modify_write_cptr_el3( void )
{
    read_modify_write_cptr_el3( .res0_7_0=1 );
}

