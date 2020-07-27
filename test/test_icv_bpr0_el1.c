

#include "sysreg/icv_bpr0_el1.h"


u64 test_read_icv_bpr0_el1( void )
{
    return read_icv_bpr0_el1().binarypoint;
}


void test_unsafe_write_icv_bpr0_el1( void )
{
    unsafe_write_icv_bpr0_el1((union icv_bpr0_el1){ .binarypoint=1 });
}


void test_safe_write_icv_bpr0_el1( void )
{
    safe_write_icv_bpr0_el1( .binarypoint=1 );
}


void test_read_modify_write_icv_bpr0_el1( void )
{
    read_modify_write_icv_bpr0_el1( .binarypoint=1 );
}

