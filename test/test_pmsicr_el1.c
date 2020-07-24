

#include "sysreg/pmsicr_el1.h"


u64 test_read_pmsicr_el1( void )
{
    return read_pmsicr_el1().count;
}


void test_unsafe_write_pmsicr_el1( void )
{
    unsafe_write_pmsicr_el1((union pmsicr_el1){ .count=1 });
}


void test_safe_write_pmsicr_el1( void )
{
    safe_write_pmsicr_el1( .count=1 );
}


void test_read_modify_write_pmsicr_el1( void )
{
    read_modify_write_pmsicr_el1( .count=1 );
}

