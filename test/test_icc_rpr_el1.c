

#include "sysreg/icc_rpr_el1.h"


u64 test_read_icc_rpr_el1( void )
{
    return read_icc_rpr_el1().priority;
}




