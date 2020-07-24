

#include "sysreg/oseccr_el1.h"


u64 test_read_oseccr_el1( void )
{
    return read_oseccr_el1().edeccr;
}


void test_unsafe_write_oseccr_el1( void )
{
    unsafe_write_oseccr_el1((union oseccr_el1){ .edeccr=1 });
}


void test_safe_write_oseccr_el1( void )
{
    safe_write_oseccr_el1( .edeccr=1 );
}


void test_read_modify_write_oseccr_el1( void )
{
    read_modify_write_oseccr_el1( .edeccr=1 );
}

