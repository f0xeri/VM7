//
// Created by Yaroslav on 05.09.2020.
//

#ifndef VM7_PROCESSOR_H
#define VM7_PROCESSOR_H

#include <cstdint>
#include <vector>
#include "Commands.h"
#include "Registers.h"
#include "Memory.h"


class Processor
{
    Registers regs;
    std::vector<Command*> commands;

public:
    enum opcodes
    {
        stop = 000,
        in = 001, out = 002, icmp = 003, uicmp = 004, rcmp = 005, call = 006, ret = 007,
        iadd = 010, uiadd = 011, radd = 012,
        isub = 020, uisub = 021, rsub = 022,
        imul = 030, uimul = 031, rmul = 032,
        idiv = 040, uidiv = 041, rdiv = 042, imod = 043, uimod = 044,
        _and = 050, _or = 051, _xor = 052, shiftr = 053, shiftl = 054,
        movrr = 060, movrs = 061, movsr = 062,
        jmp = 070, jmpr = 071, jmpi = 072, je = 073, jg = 074, jl = 075, ja = 076, jb = 077,
    };
    Memory memory;
    Processor();
    void Run();
    void SetIP(unsigned short address);
    void InitCommands();

    command16 GetCommand16(const Memory &mem, unsigned char address);
    command32 GetCommand(const Memory &mem, unsigned char address);
};


#endif //VM7_PROCESSOR_H
