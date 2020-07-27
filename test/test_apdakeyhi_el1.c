

#include "sysreg/apdakeyhi_el1.h"


u64 test_read_apdakeyhi_el1( void )
{
    return read_apdakeyhi_el1().64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value;
}


void test_unsafe_write_apdakeyhi_el1( void )
{
    unsafe_write_apdakeyhi_el1((union apdakeyhi_el1){ .64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value=1 });
}


void test_safe_write_apdakeyhi_el1( void )
{
    safe_write_apdakeyhi_el1( .64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value=1 );
}


void test_read_modify_write_apdakeyhi_el1( void )
{
    read_modify_write_apdakeyhi_el1( .64_bit_value,_bits_127_64__of_the_128_bit_pointer_authentication_key_value=1 );
}
