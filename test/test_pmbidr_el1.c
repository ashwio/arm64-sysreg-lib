

#include "sysreg/pmbidr_el1.h"


u64 test_read_pmbidr_el1( void )
{
    return read_pmbidr_el1().align;
}




