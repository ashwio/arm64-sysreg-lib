

#include "sysreg/ich_vmcr_el2.h"


u64 test_read_ich_vmcr_el2( void )
{
    return read_ich_vmcr_el2().veng0;
}


void test_unsafe_write_ich_vmcr_el2( void )
{
    unsafe_write_ich_vmcr_el2((union ich_vmcr_el2){ .veng0=1 });
}


void test_safe_write_ich_vmcr_el2( void )
{
    safe_write_ich_vmcr_el2( .veng0=1 );
}


void test_read_modify_write_ich_vmcr_el2( void )
{
    read_modify_write_ich_vmcr_el2( .veng0=1 );
}

