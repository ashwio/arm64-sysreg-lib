

#include "sysreg/midr_el1.h"


u64 test_read_midr_el1( void )
{
    return read_midr_el1().revision;
}




