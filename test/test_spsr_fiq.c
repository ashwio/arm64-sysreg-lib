

#include "sysreg/spsr_fiq.h"


u64 test_read_spsr_fiq( void )
{
    return read_spsr_fiq().m_4_0_;
}


void test_unsafe_write_spsr_fiq( void )
{
    unsafe_write_spsr_fiq((union spsr_fiq){ .m_4_0_=1 });
}


void test_safe_write_spsr_fiq( void )
{
    safe_write_spsr_fiq( .m_4_0_=1 );
}


void test_read_modify_write_spsr_fiq( void )
{
    read_modify_write_spsr_fiq( .m_4_0_=1 );
}

