

#include "sysreg/dbgdtr_el0.h"


u64 test_read_dbgdtr_el0( void )
{
    return read_dbgdtr_el0().lowword;
}


void test_unsafe_write_dbgdtr_el0( void )
{
    unsafe_write_dbgdtr_el0((union dbgdtr_el0){ .lowword=1 });
}


void test_safe_write_dbgdtr_el0( void )
{
    safe_write_dbgdtr_el0( .lowword=1 );
}


void test_read_modify_write_dbgdtr_el0( void )
{
    read_modify_write_dbgdtr_el0( .lowword=1 );
}

