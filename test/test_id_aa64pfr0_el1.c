

#include "sysreg/id_aa64pfr0_el1.h"


u64 test_read_id_aa64pfr0_el1( void )
{
    return read_id_aa64pfr0_el1().el0;
}




