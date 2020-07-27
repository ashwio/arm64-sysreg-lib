

#include "sysreg/cntpctss_el0.h"


u64 test_read_cntpctss_el0( void )
{
    return read_cntpctss_el0().Self-synchronized_physical_count_value;
}




