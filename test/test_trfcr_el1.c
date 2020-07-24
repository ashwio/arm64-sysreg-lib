

#include "sysreg/trfcr_el1.h"


u64 test_read_trfcr_el1( void )
{
    return read_trfcr_el1().e0tre;
}


void test_unsafe_write_trfcr_el1( void )
{
    unsafe_write_trfcr_el1((union trfcr_el1){ .e0tre=1 });
}


void test_safe_write_trfcr_el1( void )
{
    safe_write_trfcr_el1( .e0tre=1 );
}


void test_read_modify_write_trfcr_el1( void )
{
    read_modify_write_trfcr_el1( .e0tre=1 );
}

