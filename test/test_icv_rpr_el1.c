

#include "sysreg/icv_rpr_el1.h"


u64 test_read_icv_rpr_el1( void )
{
    return read_icv_rpr_el1().priority;
}




