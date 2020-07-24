

#include "sysreg/pmccntr_el0.h"


u64 test_read_pmccntr_el0( void )
{
    return read_pmccntr_el0().ccnt;
}


void test_unsafe_write_pmccntr_el0( void )
{
    unsafe_write_pmccntr_el0((union pmccntr_el0){ .ccnt=1 });
}


void test_safe_write_pmccntr_el0( void )
{
    safe_write_pmccntr_el0( .ccnt=1 );
}


void test_read_modify_write_pmccntr_el0( void )
{
    read_modify_write_pmccntr_el0( .ccnt=1 );
}

