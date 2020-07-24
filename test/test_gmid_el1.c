

#include "sysreg/gmid_el1.h"


u64 test_read_gmid_el1( void )
{
    return read_gmid_el1().bs;
}




