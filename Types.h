//
// Created by Yaroslav on 17.10.2020.
//

#ifndef VM7_TYPES_H
#define VM7_TYPES_H

#pragma pack(push, 1)

struct command16
{
    unsigned short opcode : 6;
    unsigned short r1 : 5;
    unsigned short r2 : 5;
};

struct command32
{
    command16 cmd;
    unsigned short address : 16;
};

union data
{
    int integer;
    unsigned int uinteger;
    float real;
};

union word
{
    data data_;
    command16 cmd16[2];
    command32 cmd32;
    unsigned char bytes[4];
};
#pragma pack(pop)
#endif //VM7_TYPES_H
