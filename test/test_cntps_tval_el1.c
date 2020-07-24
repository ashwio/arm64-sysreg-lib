

#include "sysreg/cntps_tval_el1.h"


u64 test_read_cntps_tval_el1( void )
{
    return read_cntps_tval_el1().timervalue;
}


void test_unsafe_write_cntps_tval_el1( void )
{
    unsafe_write_cntps_tval_el1((union cntps_tval_el1){ .timervalue=1 });
}


void test_safe_write_cntps_tval_el1( void )
{
    safe_write_cntps_tval_el1( .timervalue=1 );
}


void test_read_modify_write_cntps_tval_el1( void )
{
    read_modify_write_cntps_tval_el1( .timervalue=1 );
}

