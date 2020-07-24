

#include "sysreg/dbgauthstatus_el1.h"


u64 test_read_dbgauthstatus_el1( void )
{
    return read_dbgauthstatus_el1().nsid;
}




