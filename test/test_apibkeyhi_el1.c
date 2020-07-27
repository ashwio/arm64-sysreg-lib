

#include "sysreg/apibkeyhi_el1.h"


u64 test_read_apibkeyhi_el1( void )
{
    return read_apibkeyhi_el1().bits_127_64_of_the_128_bit_pointer_authentication_key_value;
}


void test_unsafe_write_apibkeyhi_el1( void )
{
    unsafe_write_apibkeyhi_el1((union apibkeyhi_el1){ .bits_127_64_of_the_128_bit_pointer_authentication_key_value=1 });
}


void test_safe_write_apibkeyhi_el1( void )
{
    safe_write_apibkeyhi_el1( .bits_127_64_of_the_128_bit_pointer_authentication_key_value=1 );
}


void test_read_modify_write_apibkeyhi_el1( void )
{
    read_modify_write_apibkeyhi_el1( .bits_127_64_of_the_128_bit_pointer_authentication_key_value=1 );
}

