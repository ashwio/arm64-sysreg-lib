

#include "sysreg/mdrar_el1.h"


u64 test_read_mdrar_el1( void )
{
    return read_mdrar_el1().valid;
}




