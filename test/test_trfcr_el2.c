

#include "sysreg/trfcr_el2.h"


u64 test_read_trfcr_el2( void )
{
    return read_trfcr_el2().e0htre;
}


void test_unsafe_write_trfcr_el2( void )
{
    unsafe_write_trfcr_el2((union trfcr_el2){ .e0htre=1 });
}


void test_safe_write_trfcr_el2( void )
{
    safe_write_trfcr_el2( .e0htre=1 );
}


void test_read_modify_write_trfcr_el2( void )
{
    read_modify_write_trfcr_el2( .e0htre=1 );
}

