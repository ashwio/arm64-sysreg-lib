

#include "sysreg/fpexc32_el2.h"


u64 test_read_fpexc32_el2( void )
{
    return read_fpexc32_el2().iof;
}


void test_unsafe_write_fpexc32_el2( void )
{
    unsafe_write_fpexc32_el2((union fpexc32_el2){ .iof=1 });
}


void test_safe_write_fpexc32_el2( void )
{
    safe_write_fpexc32_el2( .iof=1 );
}


void test_read_modify_write_fpexc32_el2( void )
{
    read_modify_write_fpexc32_el2( .iof=1 );
}

