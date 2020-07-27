

#include "sysreg/dbgdtrtx_el0.h"



void test_unsafe_write_dbgdtrtx_el0( void )
{
    unsafe_write_dbgdtrtx_el0((union dbgdtrtx_el0){ .Return_DTRTX=1 });
}


void test_safe_write_dbgdtrtx_el0( void )
{
    safe_write_dbgdtrtx_el0( .Return_DTRTX=1 );
}


