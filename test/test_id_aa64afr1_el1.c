

#include "sysreg/id_aa64afr1_el1.h"


u64 test_read_id_aa64afr1_el1( void )
{
    return read_id_aa64afr1_el1().res0_63_0;
}




