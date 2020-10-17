//
// Created by Yaroslav on 16.10.2020.
//

#ifndef VM7_STRUCTS_H
#define VM7_STRUCTS_H


#include <cstdint>

struct cmd16
{
    uint8_t opcode : 6;
    uint8_t r1 : 5;
    uint8_t r2 : 5;
};

struct cmd32
{
    uint8_t opcode : 6;
    uint8_t r1 : 5;
    uint8_t r2 : 5;
    uint16_t address : 16;
};

#endif //VM7_STRUCTS_H
