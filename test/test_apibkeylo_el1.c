

#include "sysreg/apibkeylo_el1.h"


u64 test_read_apibkeylo_el1( void )
{
    return read_apibkeylo_el1().bits_63_0_of_the_128_bit_pointer_authentication_key_value;
}


void test_unsafe_write_apibkeylo_el1( void )
{
    unsafe_write_apibkeylo_el1((union apibkeylo_el1){ .bits_63_0_of_the_128_bit_pointer_authentication_key_value=1 });
}


void test_safe_write_apibkeylo_el1( void )
{
    safe_write_apibkeylo_el1( .bits_63_0_of_the_128_bit_pointer_authentication_key_value=1 );
}


void test_read_modify_write_apibkeylo_el1( void )
{
    read_modify_write_apibkeylo_el1( .bits_63_0_of_the_128_bit_pointer_authentication_key_value=1 );
}

