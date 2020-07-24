

#include "sysreg/icc_eoir1_el1.h"



void test_unsafe_write_icc_eoir1_el1( void )
{
    unsafe_write_icc_eoir1_el1((union icc_eoir1_el1){ .intid=1 });
}


void test_safe_write_icc_eoir1_el1( void )
{
    safe_write_icc_eoir1_el1( .intid=1 );
}


