

#include "sysreg/mpam2_el2.h"


u64 test_read_mpam2_el2( void )
{
    return read_mpam2_el2().partid_i;
}


void test_unsafe_write_mpam2_el2( void )
{
    unsafe_write_mpam2_el2((union mpam2_el2){ .partid_i=1 });
}


void test_safe_write_mpam2_el2( void )
{
    safe_write_mpam2_el2( .partid_i=1 );
}


void test_read_modify_write_mpam2_el2( void )
{
    read_modify_write_mpam2_el2( .partid_i=1 );
}

