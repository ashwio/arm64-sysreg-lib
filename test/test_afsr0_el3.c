

#include "sysreg/afsr0_el3.h"


u64 test_read_afsr0_el3( void )
{
    return read_afsr0_el3().impdef_63_0;
}


void test_unsafe_write_afsr0_el3( void )
{
    unsafe_write_afsr0_el3((union afsr0_el3){ .impdef_63_0=1 });
}


void test_safe_write_afsr0_el3( void )
{
    safe_write_afsr0_el3( .impdef_63_0=1 );
}


void test_read_modify_write_afsr0_el3( void )
{
    read_modify_write_afsr0_el3( .impdef_63_0=1 );
}

