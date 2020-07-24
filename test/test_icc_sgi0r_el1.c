

#include "sysreg/icc_sgi0r_el1.h"



void test_unsafe_write_icc_sgi0r_el1( void )
{
    unsafe_write_icc_sgi0r_el1((union icc_sgi0r_el1){ .targetlist=1 });
}


void test_safe_write_icc_sgi0r_el1( void )
{
    safe_write_icc_sgi0r_el1( .targetlist=1 );
}


