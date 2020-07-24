

#include "sysreg/cnthps_tval_el2.h"


u64 test_read_cnthps_tval_el2( void )
{
    return read_cnthps_tval_el2().timervalue;
}


void test_unsafe_write_cnthps_tval_el2( void )
{
    unsafe_write_cnthps_tval_el2((union cnthps_tval_el2){ .timervalue=1 });
}


void test_safe_write_cnthps_tval_el2( void )
{
    safe_write_cnthps_tval_el2( .timervalue=1 );
}


void test_read_modify_write_cnthps_tval_el2( void )
{
    read_modify_write_cnthps_tval_el2( .timervalue=1 );
}

