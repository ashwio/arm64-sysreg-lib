

#include "sysreg/mpamvpm1_el2.h"


u64 test_read_mpamvpm1_el2( void )
{
    return read_mpamvpm1_el2().phypartid4;
}


void test_unsafe_write_mpamvpm1_el2( void )
{
    unsafe_write_mpamvpm1_el2((union mpamvpm1_el2){ .phypartid4=1 });
}


void test_safe_write_mpamvpm1_el2( void )
{
    safe_write_mpamvpm1_el2( .phypartid4=1 );
}


void test_read_modify_write_mpamvpm1_el2( void )
{
    read_modify_write_mpamvpm1_el2( .phypartid4=1 );
}

