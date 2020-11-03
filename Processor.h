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
        stop = 0,
        iadd = 1, isub = 2, imul = 3, idiv = 4, imod = 5,
        uiadd = 6, uisub = 7, uimul = 8, uidiv = 9, uimod = 10,
        radd = 11, rsub = 12, rmul = 13, rdiv = 14,
        iand = 15, ior = 16, ixor = 17, inot = 19,
        uiand = 19, uior = 20, uixor = 21, uinot = 22,
        movrr = 23, movrs = 24, movsr = 25,
        ldstr, prtstr
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
