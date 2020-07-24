

#include "sysreg/cntp_tval_el0.h"


u64 test_read_cntp_tval_el0( void )
{
    return read_cntp_tval_el0().timervalue;
}


void test_unsafe_write_cntp_tval_el0( void )
{
    unsafe_write_cntp_tval_el0((union cntp_tval_el0){ .timervalue=1 });
}


void test_safe_write_cntp_tval_el0( void )
{
    safe_write_cntp_tval_el0( .timervalue=1 );
}


void test_read_modify_write_cntp_tval_el0( void )
{
    read_modify_write_cntp_tval_el0( .timervalue=1 );
}

