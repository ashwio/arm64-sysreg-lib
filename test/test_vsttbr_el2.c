

#include "sysreg/vsttbr_el2.h"


u64 test_read_vsttbr_el2( void )
{
    return read_vsttbr_el2().cnp;
}


void test_unsafe_write_vsttbr_el2( void )
{
    unsafe_write_vsttbr_el2((union vsttbr_el2){ .cnp=1 });
}


void test_safe_write_vsttbr_el2( void )
{
    safe_write_vsttbr_el2( .cnp=1 );
}


void test_read_modify_write_vsttbr_el2( void )
{
    read_modify_write_vsttbr_el2( .cnp=1 );
}

