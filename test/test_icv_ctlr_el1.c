

#include "sysreg/icv_ctlr_el1.h"


u64 test_read_icv_ctlr_el1( void )
{
    return read_icv_ctlr_el1().cbpr;
}


void test_unsafe_write_icv_ctlr_el1( void )
{
    unsafe_write_icv_ctlr_el1((union icv_ctlr_el1){ .cbpr=1 });
}


void test_safe_write_icv_ctlr_el1( void )
{
    safe_write_icv_ctlr_el1( .cbpr=1 );
}


void test_read_modify_write_icv_ctlr_el1( void )
{
    read_modify_write_icv_ctlr_el1( .cbpr=1 );
}

