

#include "sysreg/icc_bpr1_el1.h"


u64 test_read_icc_bpr1_el1( void )
{
    return read_icc_bpr1_el1().binarypoint;
}


void test_unsafe_write_icc_bpr1_el1( void )
{
    unsafe_write_icc_bpr1_el1((union icc_bpr1_el1){ .binarypoint=1 });
}


void test_safe_write_icc_bpr1_el1( void )
{
    safe_write_icc_bpr1_el1( .binarypoint=1 );
}


void test_read_modify_write_icc_bpr1_el1( void )
{
    read_modify_write_icc_bpr1_el1( .binarypoint=1 );
}

