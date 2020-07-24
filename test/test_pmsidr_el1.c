

#include "sysreg/pmsidr_el1.h"


u64 test_read_pmsidr_el1( void )
{
    return read_pmsidr_el1().fe;
}




