

#include "sysreg/cntpoff_el2.h"


u64 test_read_cntpoff_el2( void )
{
    return read_cntpoff_el2().Physical_offset;
}


void test_unsafe_write_cntpoff_el2( void )
{
    unsafe_write_cntpoff_el2((union cntpoff_el2){ .Physical_offset=1 });
}


void test_safe_write_cntpoff_el2( void )
{
    safe_write_cntpoff_el2( .Physical_offset=1 );
}


void test_read_modify_write_cntpoff_el2( void )
{
    read_modify_write_cntpoff_el2( .Physical_offset=1 );
}

