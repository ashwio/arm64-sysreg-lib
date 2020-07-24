

#include "sysreg/contextidr_el2.h"


u64 test_read_contextidr_el2( void )
{
    return read_contextidr_el2().procid;
}


void test_unsafe_write_contextidr_el2( void )
{
    unsafe_write_contextidr_el2((union contextidr_el2){ .procid=1 });
}


void test_safe_write_contextidr_el2( void )
{
    safe_write_contextidr_el2( .procid=1 );
}


void test_read_modify_write_contextidr_el2( void )
{
    read_modify_write_contextidr_el2( .procid=1 );
}

