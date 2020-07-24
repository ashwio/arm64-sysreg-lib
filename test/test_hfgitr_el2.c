

#include "sysreg/hfgitr_el2.h"


u64 test_read_hfgitr_el2( void )
{
    return read_hfgitr_el2().icialluis;
}


void test_unsafe_write_hfgitr_el2( void )
{
    unsafe_write_hfgitr_el2((union hfgitr_el2){ .icialluis=1 });
}


void test_safe_write_hfgitr_el2( void )
{
    safe_write_hfgitr_el2( .icialluis=1 );
}


void test_read_modify_write_hfgitr_el2( void )
{
    read_modify_write_hfgitr_el2( .icialluis=1 );
}

