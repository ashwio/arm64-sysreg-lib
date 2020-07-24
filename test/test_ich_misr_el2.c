

#include "sysreg/ich_misr_el2.h"


u64 test_read_ich_misr_el2( void )
{
    return read_ich_misr_el2().eoi;
}




