

#include "sysreg/amair_el1.h"


u64 test_read_amair_el1( void )
{
    return read_amair_el1().impdef_63_0;
}


void test_unsafe_write_amair_el1( void )
{
    unsafe_write_amair_el1((union amair_el1){ .impdef_63_0=1 });
}


void test_safe_write_amair_el1( void )
{
    safe_write_amair_el1( .impdef_63_0=1 );
}


void test_read_modify_write_amair_el1( void )
{
    read_modify_write_amair_el1( .impdef_63_0=1 );
}

