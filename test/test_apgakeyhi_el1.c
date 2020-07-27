

#include "sysreg/apgakeyhi_el1.h"


u64 test_read_apgakeyhi_el1( void )
{
    return read_apgakeyhi_el1().bits_127_64_of_the_128_bit_pointer_authentication_key_value;
}


void test_unsafe_write_apgakeyhi_el1( void )
{
    unsafe_write_apgakeyhi_el1((union apgakeyhi_el1){ .bits_127_64_of_the_128_bit_pointer_authentication_key_value=1 });
}


void test_safe_write_apgakeyhi_el1( void )
{
    safe_write_apgakeyhi_el1( .bits_127_64_of_the_128_bit_pointer_authentication_key_value=1 );
}


void test_read_modify_write_apgakeyhi_el1( void )
{
    read_modify_write_apgakeyhi_el1( .bits_127_64_of_the_128_bit_pointer_authentication_key_value=1 );
}

