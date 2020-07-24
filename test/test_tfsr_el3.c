

#include "sysreg/tfsr_el3.h"


u64 test_read_tfsr_el3( void )
{
    return read_tfsr_el3().tf0;
}


void test_unsafe_write_tfsr_el3( void )
{
    unsafe_write_tfsr_el3((union tfsr_el3){ .tf0=1 });
}


void test_safe_write_tfsr_el3( void )
{
    safe_write_tfsr_el3( .tf0=1 );
}


void test_read_modify_write_tfsr_el3( void )
{
    read_modify_write_tfsr_el3( .tf0=1 );
}

