

#include "sysreg/scr_el3.h"


u64 test_read_scr_el3( void )
{
    return read_scr_el3().ns;
}


void test_unsafe_write_scr_el3( void )
{
    unsafe_write_scr_el3((union scr_el3){ .ns=1 });
}


void test_safe_write_scr_el3( void )
{
    safe_write_scr_el3( .ns=1 );
}


void test_read_modify_write_scr_el3( void )
{
    read_modify_write_scr_el3( .ns=1 );
}

