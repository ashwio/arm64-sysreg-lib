

#include "sysreg/cntvct_el0.h"


u64 test_read_cntvct_el0( void )
{
    return read_cntvct_el0().Virtual_count_value;
}




