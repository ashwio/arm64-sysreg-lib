

#include "sysreg/aidr_el1.h"


u64 test_read_aidr_el1( void )
{
    return read_aidr_el1().impdef_63_0;
}




