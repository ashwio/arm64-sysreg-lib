

#include "sysreg/mpam1_el1.h"


u64 test_read_mpam1_el1( void )
{
    return read_mpam1_el1().partid_i;
}


void test_unsafe_write_mpam1_el1( void )
{
    unsafe_write_mpam1_el1((union mpam1_el1){ .partid_i=1 });
}


void test_safe_write_mpam1_el1( void )
{
    safe_write_mpam1_el1( .partid_i=1 );
}


void test_read_modify_write_mpam1_el1( void )
{
    read_modify_write_mpam1_el1( .partid_i=1 );
}

