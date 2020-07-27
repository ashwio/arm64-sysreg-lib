

#include "sysreg/cntpct_el0.h"


u64 test_read_cntpct_el0( void )
{
    return read_cntpct_el0().Physical_count_value;
}




