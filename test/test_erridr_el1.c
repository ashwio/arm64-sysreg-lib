

#include "sysreg/erridr_el1.h"


u64 test_read_erridr_el1( void )
{
    return read_erridr_el1().num;
}




