

#include "sysreg/icc_iar1_el1.h"


u64 test_read_icc_iar1_el1( void )
{
    return read_icc_iar1_el1().intid;
}




