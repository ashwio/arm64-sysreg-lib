

#include "sysreg/pmxevtyper_el0.h"


u64 test_read_pmxevtyper_el0( void )
{
    return read_pmxevtyper_el0().Event_type_register_or_PMCCFILTR_EL0;
}


void test_unsafe_write_pmxevtyper_el0( void )
{
    unsafe_write_pmxevtyper_el0((union pmxevtyper_el0){ .Event_type_register_or_PMCCFILTR_EL0=1 });
}


void test_safe_write_pmxevtyper_el0( void )
{
    safe_write_pmxevtyper_el0( .Event_type_register_or_PMCCFILTR_EL0=1 );
}


void test_read_modify_write_pmxevtyper_el0( void )
{
    read_modify_write_pmxevtyper_el0( .Event_type_register_or_PMCCFILTR_EL0=1 );
}

