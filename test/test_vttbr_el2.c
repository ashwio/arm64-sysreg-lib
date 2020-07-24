

#include "sysreg/vttbr_el2.h"


u64 test_read_vttbr_el2( void )
{
    return read_vttbr_el2().cnp;
}


void test_unsafe_write_vttbr_el2( void )
{
    unsafe_write_vttbr_el2((union vttbr_el2){ .cnp=1 });
}


void test_safe_write_vttbr_el2( void )
{
    safe_write_vttbr_el2( .cnp=1 );
}


void test_read_modify_write_vttbr_el2( void )
{
    read_modify_write_vttbr_el2( .cnp=1 );
}

