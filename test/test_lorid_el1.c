

#include "sysreg/lorid_el1.h"


u64 test_read_lorid_el1( void )
{
    return read_lorid_el1().lr;
}




