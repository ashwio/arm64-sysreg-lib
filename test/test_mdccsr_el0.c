

#include "sysreg/mdccsr_el0.h"


u64 test_read_mdccsr_el0( void )
{
    return read_mdccsr_el0().res0_1_0;
}




