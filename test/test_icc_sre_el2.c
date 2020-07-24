

#include "sysreg/icc_sre_el2.h"


u64 test_read_icc_sre_el2( void )
{
    return read_icc_sre_el2().sre;
}


void test_unsafe_write_icc_sre_el2( void )
{
    unsafe_write_icc_sre_el2((union icc_sre_el2){ .sre=1 });
}


void test_safe_write_icc_sre_el2( void )
{
    safe_write_icc_sre_el2( .sre=1 );
}


void test_read_modify_write_icc_sre_el2( void )
{
    read_modify_write_icc_sre_el2( .sre=1 );
}

