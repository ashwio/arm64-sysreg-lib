

#include "sysreg/ich_vtr_el2.h"


u64 test_read_ich_vtr_el2( void )
{
    return read_ich_vtr_el2().listregs;
}




