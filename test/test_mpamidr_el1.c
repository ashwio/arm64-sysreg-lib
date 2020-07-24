

#include "sysreg/mpamidr_el1.h"


u64 test_read_mpamidr_el1( void )
{
    return read_mpamidr_el1().partid_max;
}




