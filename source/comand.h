#pragma once

#include "counter.h"
#include <cstdint>

typedef enum : char
{
    INC = '+',
    DEC = '-',
    READ = '=',
    STOP = 'x',
    UNKNOWN = '?'
}command_t;

struct Command
{
    Counter * __counter = nullptr;
    
    Command(void);
    ~Command(void);
    Command(const Command & command);
    Command & operator= (const Command & command);

    void run(void);
};