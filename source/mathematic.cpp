#include "mathematic.h"

int32_t summ_int32(int32_t in_1, int32_t in_2)
{
    return in_1 + in_2;
}

int32_t diff_int32(int32_t in_1, int32_t in_2)
{
    return in_1 - in_2;
}

int32_t mult_int32(int32_t in_1, int32_t in_2)
{
    return in_1 * in_2;
}

int32_t div_int32(int32_t in_1, int32_t in_2)
{
    return in_1 / in_2;
}

uint32_t pow_uint32(uint32_t value, uint8_t stepen)
{
    uint32_t result = 1;
    while(stepen--)
    {
        result *= value;
    }
    return result;
}
