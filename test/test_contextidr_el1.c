

#include "sysreg/contextidr_el1.h"


u64 test_read_contextidr_el1( void )
{
    return read_contextidr_el1().procid;
}


void test_unsafe_write_contextidr_el1( void )
{
    unsafe_write_contextidr_el1((union contextidr_el1){ .procid=1 });
}


void test_safe_write_contextidr_el1( void )
{
    safe_write_contextidr_el1( .procid=1 );
}


void test_read_modify_write_contextidr_el1( void )
{
    read_modify_write_contextidr_el1( .procid=1 );
}

