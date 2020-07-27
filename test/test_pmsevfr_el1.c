

#include "sysreg/pmsevfr_el1.h"


u64 test_read_pmsevfr_el1( void )
{
    return read_pmsevfr_el1().res0_0;
}


void test_unsafe_write_pmsevfr_el1( void )
{
    unsafe_write_pmsevfr_el1((union pmsevfr_el1){ .res0_0=1 });
}


void test_safe_write_pmsevfr_el1( void )
{
    safe_write_pmsevfr_el1( .res0_0=1 );
}


void test_read_modify_write_pmsevfr_el1( void )
{
    read_modify_write_pmsevfr_el1( .res0_0=1 );
}

