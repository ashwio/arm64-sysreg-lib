

#include "sysreg/pmslatfr_el1.h"


u64 test_read_pmslatfr_el1( void )
{
    return read_pmslatfr_el1().minlat;
}


void test_unsafe_write_pmslatfr_el1( void )
{
    unsafe_write_pmslatfr_el1((union pmslatfr_el1){ .minlat=1 });
}


void test_safe_write_pmslatfr_el1( void )
{
    safe_write_pmslatfr_el1( .minlat=1 );
}


void test_read_modify_write_pmslatfr_el1( void )
{
    read_modify_write_pmslatfr_el1( .minlat=1 );
}

