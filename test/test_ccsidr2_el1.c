

#include "sysreg/ccsidr2_el1.h"


u64 test_read_ccsidr2_el1( void )
{
    return read_ccsidr2_el1().numsets;
}




