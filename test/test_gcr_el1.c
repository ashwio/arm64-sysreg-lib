

#include "sysreg/gcr_el1.h"


u64 test_read_gcr_el1( void )
{
    return read_gcr_el1().exclude;
}


void test_unsafe_write_gcr_el1( void )
{
    unsafe_write_gcr_el1((union gcr_el1){ .exclude=1 });
}


void test_safe_write_gcr_el1( void )
{
    safe_write_gcr_el1( .exclude=1 );
}


void test_read_modify_write_gcr_el1( void )
{
    read_modify_write_gcr_el1( .exclude=1 );
}

