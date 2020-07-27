

#include "sysreg/cntvctss_el0.h"


u64 test_read_cntvctss_el0( void )
{
    return read_cntvctss_el0().Self-synchronized_virtual_count_value;
}




