#pragma once

#include <cstdint>

#define UINT32_HIGEST_BIT_MASK (((uint32_t)1) << 31)

typedef enum : bool
{
    OK = false,
    COUNTER_OVERFLOW = !OK,
}status_t;

class Counter
{
    private:
        uint32_t __cnt;

    public:
        Counter(uint32_t cnt = 1): __cnt {cnt} {}; 
        
        uint32_t get(void) const;
        void set(uint32_t cnt);
        status_t inc(void);
        status_t dec(void);
};
