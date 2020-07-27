

#include "sysreg/dbgdtrrx_el0.h"


u64 test_read_dbgdtrrx_el0( void )
{
    return read_dbgdtrrx_el0().Update_DTRRX;
}




