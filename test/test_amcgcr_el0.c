

#include "sysreg/amcgcr_el0.h"


u64 test_read_amcgcr_el0( void )
{
    return read_amcgcr_el0().cg0nc;
}




