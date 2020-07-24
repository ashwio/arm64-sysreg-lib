

#include "sysreg/pmmir_el1.h"


u64 test_read_pmmir_el1( void )
{
    return read_pmmir_el1().slots;
}




