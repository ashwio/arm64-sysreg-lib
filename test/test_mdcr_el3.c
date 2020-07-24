

#include "sysreg/mdcr_el3.h"


u64 test_read_mdcr_el3( void )
{
    return read_mdcr_el3().res0_5_0;
}


void test_unsafe_write_mdcr_el3( void )
{
    unsafe_write_mdcr_el3((union mdcr_el3){ .res0_5_0=1 });
}


void test_safe_write_mdcr_el3( void )
{
    safe_write_mdcr_el3( .res0_5_0=1 );
}


void test_read_modify_write_mdcr_el3( void )
{
    read_modify_write_mdcr_el3( .res0_5_0=1 );
}

