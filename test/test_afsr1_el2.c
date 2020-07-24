

#include "sysreg/afsr1_el2.h"


u64 test_read_afsr1_el2( void )
{
    return read_afsr1_el2().impdef_63_0;
}


void test_unsafe_write_afsr1_el2( void )
{
    unsafe_write_afsr1_el2((union afsr1_el2){ .impdef_63_0=1 });
}


void test_safe_write_afsr1_el2( void )
{
    safe_write_afsr1_el2( .impdef_63_0=1 );
}


void test_read_modify_write_afsr1_el2( void )
{
    read_modify_write_afsr1_el2( .impdef_63_0=1 );
}

