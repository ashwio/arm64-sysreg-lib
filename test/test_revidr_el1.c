

#include "sysreg/revidr_el1.h"


u64 test_read_revidr_el1( void )
{
    return read_revidr_el1().impdef_63_0;
}




