

#include "sysreg/cntvoff_el2.h"


u64 test_read_cntvoff_el2( void )
{
    return read_cntvoff_el2().Virtual_offset;
}


void test_unsafe_write_cntvoff_el2( void )
{
    unsafe_write_cntvoff_el2((union cntvoff_el2){ .Virtual_offset=1 });
}


void test_safe_write_cntvoff_el2( void )
{
    safe_write_cntvoff_el2( .Virtual_offset=1 );
}


void test_read_modify_write_cntvoff_el2( void )
{
    read_modify_write_cntvoff_el2( .Virtual_offset=1 );
}

