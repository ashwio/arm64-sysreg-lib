

#include "sysreg/icc_ctlr_el3.h"


u64 test_read_icc_ctlr_el3( void )
{
    return read_icc_ctlr_el3().cbpr_el1s;
}


void test_unsafe_write_icc_ctlr_el3( void )
{
    unsafe_write_icc_ctlr_el3((union icc_ctlr_el3){ .cbpr_el1s=1 });
}


void test_safe_write_icc_ctlr_el3( void )
{
    safe_write_icc_ctlr_el3( .cbpr_el1s=1 );
}


void test_read_modify_write_icc_ctlr_el3( void )
{
    read_modify_write_icc_ctlr_el3( .cbpr_el1s=1 );
}

