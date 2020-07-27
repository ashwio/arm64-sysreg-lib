

#include "sysreg/rvbar_el1.h"


u64 test_read_rvbar_el1( void )
{
    return read_rvbar_el1().Reset_Address;
}




