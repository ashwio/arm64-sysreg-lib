

#include "sysreg/mpamvpm6_el2.h"


u64 test_read_mpamvpm6_el2( void )
{
    return read_mpamvpm6_el2().phypartid24;
}


void test_unsafe_write_mpamvpm6_el2( void )
{
    unsafe_write_mpamvpm6_el2((union mpamvpm6_el2){ .phypartid24=1 });
}


void test_safe_write_mpamvpm6_el2( void )
{
    safe_write_mpamvpm6_el2( .phypartid24=1 );
}


void test_read_modify_write_mpamvpm6_el2( void )
{
    read_modify_write_mpamvpm6_el2( .phypartid24=1 );
}

