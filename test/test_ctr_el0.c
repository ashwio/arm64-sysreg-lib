

#include "sysreg/ctr_el0.h"


u64 test_read_ctr_el0( void )
{
    return read_ctr_el0().iminline;
}




