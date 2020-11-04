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
    /*enum opcodes
    {
        stop = 0,
        iadd = 1, isub = 2, imul = 3, idiv = 4, imod = 5,
        uiadd = 6, uisub = 7, uimul = 8, uidiv = 9, uimod = 10,
        radd = 11, rsub = 12, rmul = 13, rdiv = 14,
        iand = 15, ior = 16, ixor = 17, inot = 19,
        uiand = 19, uior = 20, uixor = 21, uinot = 22,
        movrr = 23, movrs = 24, movsr = 25,
        ldstr, prtstr
    };*/
    enum opcodes
    {
        stop = 000,
        in = 001, out = 002, icmp = 003, uicmp = 004, rcmp = 005,
        iadd = 010, uiadd = 011, radd = 012,
        isub = 020, uisub = 021, rsub = 022,
        imul = 030, uimul = 031, rmul = 032,
        idiv = 040, uidiv = 041, rdiv = 042, imod = 043, uimod = 044,
        _and = 050, _or = 051, _xor = 052, shiftr = 053, shiftl = 054,
        movrr = 060, movrs = 061, movsr = 062,
        jmp = 070, je = 071, jg = 072, jl = 073, ja = 074, jb = 075
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
