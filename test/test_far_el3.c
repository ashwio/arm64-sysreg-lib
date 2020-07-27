

#include "sysreg/far_el3.h"


u64 test_read_far_el3( void )
{
    return read_far_el3().Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL3;
}


void test_unsafe_write_far_el3( void )
{
    unsafe_write_far_el3((union far_el3){ .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL3=1 });
}


void test_safe_write_far_el3( void )
{
    safe_write_far_el3( .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL3=1 );
}


void test_read_modify_write_far_el3( void )
{
    read_modify_write_far_el3( .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL3=1 );
}

