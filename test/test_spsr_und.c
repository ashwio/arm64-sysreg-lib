

#include "sysreg/spsr_und.h"


u64 test_read_spsr_und( void )
{
    return read_spsr_und().m_4_0_;
}


void test_unsafe_write_spsr_und( void )
{
    unsafe_write_spsr_und((union spsr_und){ .m_4_0_=1 });
}


void test_safe_write_spsr_und( void )
{
    safe_write_spsr_und( .m_4_0_=1 );
}


void test_read_modify_write_spsr_und( void )
{
    read_modify_write_spsr_und( .m_4_0_=1 );
}

