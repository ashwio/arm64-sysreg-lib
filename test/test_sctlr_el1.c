

#include "sysreg/sctlr_el1.h"


u64 test_read_sctlr_el1( void )
{
    return read_sctlr_el1().m;
}


void test_unsafe_write_sctlr_el1( void )
{
    unsafe_write_sctlr_el1((union sctlr_el1){ .m=1 });
}


void test_safe_write_sctlr_el1( void )
{
    safe_write_sctlr_el1( .m=1 );
}


void test_read_modify_write_sctlr_el1( void )
{
    read_modify_write_sctlr_el1( .m=1 );
}

