//
// Created by Yaroslav on 16.10.2020.
//

#ifndef VM7_REGISTERS_H
#define VM7_REGISTERS_H


#include <cstdint>
#include <exception>
#include "Types.h"

class Registers
{
public:
    data grp[32]{};
    data &operator[](uint8_t n) {
        return grp[n];
    }
};


#endif //VM7_REGISTERS_H
