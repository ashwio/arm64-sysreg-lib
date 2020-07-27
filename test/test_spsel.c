

#include "sysreg/spsel.h"


u64 test_read_spsel( void )
{
    return read_spsel().sp;
}


void test_unsafe_write_spsel( void )
{
    unsafe_write_spsel((union spsel){ .sp=1 });
}


void test_safe_write_spsel( void )
{
    safe_write_spsel( .sp=1 );
}


void test_read_modify_write_spsel( void )
{
    read_modify_write_spsel( .sp=1 );
}

