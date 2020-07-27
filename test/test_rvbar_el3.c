

#include "sysreg/rvbar_el3.h"


u64 test_read_rvbar_el3( void )
{
    return read_rvbar_el3().Reset_Address;
}




