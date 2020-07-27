

#include "sysreg/spsr_abt.h"


u64 test_read_spsr_abt( void )
{
    return read_spsr_abt().m_4_0_;
}


void test_unsafe_write_spsr_abt( void )
{
    unsafe_write_spsr_abt((union spsr_abt){ .m_4_0_=1 });
}


void test_safe_write_spsr_abt( void )
{
    safe_write_spsr_abt( .m_4_0_=1 );
}


void test_read_modify_write_spsr_abt( void )
{
    read_modify_write_spsr_abt( .m_4_0_=1 );
}

