

#include "sysreg/mpidr_el1.h"


u64 test_read_mpidr_el1( void )
{
    return read_mpidr_el1().aff0;
}




