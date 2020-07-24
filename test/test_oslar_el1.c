

#include "sysreg/oslar_el1.h"



void test_unsafe_write_oslar_el1( void )
{
    unsafe_write_oslar_el1((union oslar_el1){ .oslk=1 });
}


void test_safe_write_oslar_el1( void )
{
    safe_write_oslar_el1( .oslk=1 );
}


