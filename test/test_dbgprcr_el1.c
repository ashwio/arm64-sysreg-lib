

#include "sysreg/dbgprcr_el1.h"


u64 test_read_dbgprcr_el1( void )
{
    return read_dbgprcr_el1().corenpdrq;
}


void test_unsafe_write_dbgprcr_el1( void )
{
    unsafe_write_dbgprcr_el1((union dbgprcr_el1){ .corenpdrq=1 });
}


void test_safe_write_dbgprcr_el1( void )
{
    safe_write_dbgprcr_el1( .corenpdrq=1 );
}


void test_read_modify_write_dbgprcr_el1( void )
{
    read_modify_write_dbgprcr_el1( .corenpdrq=1 );
}

