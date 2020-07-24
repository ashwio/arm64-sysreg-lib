

#include "sysreg/oslsr_el1.h"


u64 test_read_oslsr_el1( void )
{
    return read_oslsr_el1().oslm_0_;
}




