

#include "sysreg/pmscr_el1.h"


u64 test_read_pmscr_el1( void )
{
    return read_pmscr_el1().e0spe;
}


void test_unsafe_write_pmscr_el1( void )
{
    unsafe_write_pmscr_el1((union pmscr_el1){ .e0spe=1 });
}


void test_safe_write_pmscr_el1( void )
{
    safe_write_pmscr_el1( .e0spe=1 );
}


void test_read_modify_write_pmscr_el1( void )
{
    read_modify_write_pmscr_el1( .e0spe=1 );
}

