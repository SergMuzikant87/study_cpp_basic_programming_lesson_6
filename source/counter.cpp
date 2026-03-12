#include "counter.h"

uint32_t Counter::get(void) const 
{
    return __cnt;
}

void Counter::set(uint32_t cnt)
{
    __cnt = cnt;
}

status_t Counter::inc(void)
{
    uint32_t cnt_prev = __cnt;
    __cnt++;
    return static_cast<status_t>((!(__cnt & UINT32_HIGEST_BIT_MASK)) && (cnt_prev & UINT32_HIGEST_BIT_MASK));
}

status_t Counter::dec(void)
{
    uint32_t cnt_prev = __cnt;
    __cnt--;
    return static_cast<status_t>((__cnt & UINT32_HIGEST_BIT_MASK) && (!(cnt_prev & UINT32_HIGEST_BIT_MASK)));
}