

#include "sysreg/far_el2.h"


u64 test_read_far_el2( void )
{
    return read_far_el2().Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL2;
}


void test_unsafe_write_far_el2( void )
{
    unsafe_write_far_el2((union far_el2){ .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL2=1 });
}


void test_safe_write_far_el2( void )
{
    safe_write_far_el2( .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL2=1 );
}


void test_read_modify_write_far_el2( void )
{
    read_modify_write_far_el2( .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL2=1 );
}

