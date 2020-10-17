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
        stop,
        iadd, isub, imul, idiv, imod, iin, iout,
        radd, rsub, rmul, rdiv, rin, rout,
        iand, ior, ixor, inot, ldstr, prtstr
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
