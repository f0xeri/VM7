//
// Created by Yaroslav on 16.10.2020.
//

#ifndef VM7_MEMORY_H
#define VM7_MEMORY_H


#include <cstdint>
#include "Types.h"

class Memory
{
public:
    Memory() { memory = new word[65536]{}; }
    ~Memory() { delete[] memory; }

    word &operator[](uint32_t idx) {
        return memory[idx];
    };
    word *memory;
};


#endif //VM7_MEMORY_H
