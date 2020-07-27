

#include "sysreg/spsr_irq.h"


u64 test_read_spsr_irq( void )
{
    return read_spsr_irq().m_4_0_;
}


void test_unsafe_write_spsr_irq( void )
{
    unsafe_write_spsr_irq((union spsr_irq){ .m_4_0_=1 });
}


void test_safe_write_spsr_irq( void )
{
    safe_write_spsr_irq( .m_4_0_=1 );
}


void test_read_modify_write_spsr_irq( void )
{
    read_modify_write_spsr_irq( .m_4_0_=1 );
}

