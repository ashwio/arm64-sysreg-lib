

#include "sysreg/amcfgr_el0.h"


u64 test_read_amcfgr_el0( void )
{
    return read_amcfgr_el0().n;
}




