

#include "sysreg/sctlr_el3.h"


u64 test_read_sctlr_el3( void )
{
    return read_sctlr_el3().m;
}


void test_unsafe_write_sctlr_el3( void )
{
    unsafe_write_sctlr_el3((union sctlr_el3){ .m=1 });
}


void test_safe_write_sctlr_el3( void )
{
    safe_write_sctlr_el3( .m=1 );
}


void test_read_modify_write_sctlr_el3( void )
{
    read_modify_write_sctlr_el3( .m=1 );
}

