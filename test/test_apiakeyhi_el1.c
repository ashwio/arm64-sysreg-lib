

#include "sysreg/apiakeyhi_el1.h"


u64 test_read_apiakeyhi_el1( void )
{
    return read_apiakeyhi_el1().64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value;
}


void test_unsafe_write_apiakeyhi_el1( void )
{
    unsafe_write_apiakeyhi_el1((union apiakeyhi_el1){ .64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value=1 });
}


void test_safe_write_apiakeyhi_el1( void )
{
    safe_write_apiakeyhi_el1( .64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value=1 );
}


void test_read_modify_write_apiakeyhi_el1( void )
{
    read_modify_write_apiakeyhi_el1( .64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value=1 );
}

