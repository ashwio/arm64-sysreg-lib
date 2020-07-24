

#include "sysreg/dczid_el0.h"


u64 test_read_dczid_el0( void )
{
    return read_dczid_el0().bs;
}




