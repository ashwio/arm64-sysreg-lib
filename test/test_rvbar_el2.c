

#include "sysreg/rvbar_el2.h"


u64 test_read_rvbar_el2( void )
{
    return read_rvbar_el2().Reset_Address;
}




