

#include "sysreg/icc_hppir0_el1.h"


u64 test_read_icc_hppir0_el1( void )
{
    return read_icc_hppir0_el1().intid;
}




