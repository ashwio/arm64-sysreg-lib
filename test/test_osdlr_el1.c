

#include "sysreg/osdlr_el1.h"


u64 test_read_osdlr_el1( void )
{
    return read_osdlr_el1().dlk;
}


void test_unsafe_write_osdlr_el1( void )
{
    unsafe_write_osdlr_el1((union osdlr_el1){ .dlk=1 });
}


void test_safe_write_osdlr_el1( void )
{
    safe_write_osdlr_el1( .dlk=1 );
}


void test_read_modify_write_osdlr_el1( void )
{
    read_modify_write_osdlr_el1( .dlk=1 );
}

