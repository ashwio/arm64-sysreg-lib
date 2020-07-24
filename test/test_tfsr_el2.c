

#include "sysreg/tfsr_el2.h"


u64 test_read_tfsr_el2( void )
{
    return read_tfsr_el2().tf0;
}


void test_unsafe_write_tfsr_el2( void )
{
    unsafe_write_tfsr_el2((union tfsr_el2){ .tf0=1 });
}


void test_safe_write_tfsr_el2( void )
{
    safe_write_tfsr_el2( .tf0=1 );
}


void test_read_modify_write_tfsr_el2( void )
{
    read_modify_write_tfsr_el2( .tf0=1 );
}

