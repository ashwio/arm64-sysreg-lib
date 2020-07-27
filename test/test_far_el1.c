

#include "sysreg/far_el1.h"


u64 test_read_far_el1( void )
{
    return read_far_el1().Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL1;
}


void test_unsafe_write_far_el1( void )
{
    unsafe_write_far_el1((union far_el1){ .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL1=1 });
}


void test_safe_write_far_el1( void )
{
    safe_write_far_el1( .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL1=1 );
}


void test_read_modify_write_far_el1( void )
{
    read_modify_write_far_el1( .Faulting_Virtual_Address_for_synchronous_exceptions_taken_to_EL1=1 );
}

