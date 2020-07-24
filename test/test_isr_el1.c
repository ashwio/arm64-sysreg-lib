

#include "sysreg/isr_el1.h"


u64 test_read_isr_el1( void )
{
    return read_isr_el1().res0_5_0;
}




