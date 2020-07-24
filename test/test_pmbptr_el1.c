

#include "sysreg/pmbptr_el1.h"


u64 test_read_pmbptr_el1( void )
{
    return read_pmbptr_el1().ptr;
}


void test_unsafe_write_pmbptr_el1( void )
{
    unsafe_write_pmbptr_el1((union pmbptr_el1){ .ptr=1 });
}


void test_safe_write_pmbptr_el1( void )
{
    safe_write_pmbptr_el1( .ptr=1 );
}


void test_read_modify_write_pmbptr_el1( void )
{
    read_modify_write_pmbptr_el1( .ptr=1 );
}

