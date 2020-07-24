

#include "sysreg/sder32_el3.h"


u64 test_read_sder32_el3( void )
{
    return read_sder32_el3().suiden;
}


void test_unsafe_write_sder32_el3( void )
{
    unsafe_write_sder32_el3((union sder32_el3){ .suiden=1 });
}


void test_safe_write_sder32_el3( void )
{
    safe_write_sder32_el3( .suiden=1 );
}


void test_read_modify_write_sder32_el3( void )
{
    read_modify_write_sder32_el3( .suiden=1 );
}

