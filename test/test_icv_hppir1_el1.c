

#include "sysreg/icv_hppir1_el1.h"


u64 test_read_icv_hppir1_el1( void )
{
    return read_icv_hppir1_el1().intid;
}




