

#include "sysreg/mpam3_el3.h"


u64 test_read_mpam3_el3( void )
{
    return read_mpam3_el3().partid_i;
}


void test_unsafe_write_mpam3_el3( void )
{
    unsafe_write_mpam3_el3((union mpam3_el3){ .partid_i=1 });
}


void test_safe_write_mpam3_el3( void )
{
    safe_write_mpam3_el3( .partid_i=1 );
}


void test_read_modify_write_mpam3_el3( void )
{
    read_modify_write_mpam3_el3( .partid_i=1 );
}

