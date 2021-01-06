//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_COMPARE_H
#define VM7_COMPARE_H

#include <cfenv>
#include "Commands.h"

class IntegerCompare : public Compare
{
    public: void operator()(Processor &cpu) noexcept override
    {
        int temp = 0;
        if (__builtin_sub_overflow(cpu.regs[cpu.currentCommand.cmd.r1].integer, cpu.regs[cpu.currentCommand.cmd.r2].integer, &temp))
            cpu.psw.OF = 1;
        else cpu.psw.OF = 0;
        if (cpu.regs[cpu.currentCommand.cmd.r1].integer == cpu.regs[cpu.currentCommand.cmd.r2].integer)
        {
            cpu.psw.ZF = 1;
            cpu.psw.SF = 0;
            cpu.psw.CF = 0;
        }
        else if (cpu.regs[cpu.currentCommand.cmd.r1].integer < cpu.regs[cpu.currentCommand.cmd.r2].integer)
        {
            cpu.psw.ZF = 0;
            cpu.psw.SF = 1;
            cpu.psw.CF = 1;
        }
        else
        {
            cpu.psw.ZF = 0;
            cpu.psw.SF = 0;
            cpu.psw.CF = 0;
        }
        cpu.shrt = 1;
    }
};

class UIntegerCompare : public Compare
{
public: void operator()(Processor &cpu) noexcept override
    {
        unsigned int temp = 0;
        if (__builtin_sub_overflow(cpu.regs[cpu.currentCommand.cmd.r1].integer, cpu.regs[cpu.currentCommand.cmd.r2].integer, &temp))
            cpu.psw.OF = 1;
        else cpu.psw.OF = 0;
        if (cpu.regs[cpu.currentCommand.cmd.r1].uinteger == cpu.regs[cpu.currentCommand.cmd.r2].uinteger)
        {
            cpu.psw.ZF = 1;
            cpu.psw.SF = 0;
            cpu.psw.CF = 0;
        }
        else if (cpu.regs[cpu.currentCommand.cmd.r1].uinteger < cpu.regs[cpu.currentCommand.cmd.r2].uinteger)
        {
            cpu.psw.ZF = 0;
            cpu.psw.SF = 1;
            cpu.psw.CF = 1;
        }
        else
        {
            cpu.psw.ZF = 0;
            cpu.psw.SF = 0;
            cpu.psw.CF = 0;
        }
        cpu.shrt = 1;
    }
};

class RealCompare : public Compare
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.regs[cpu.currentCommand.cmd.r1].real > cpu.regs[cpu.currentCommand.cmd.r2].real) { cpu.psw.CF = 0; cpu.psw.ZF = 0; }
        else if (cpu.regs[cpu.currentCommand.cmd.r1].real < cpu.regs[cpu.currentCommand.cmd.r2].real) { cpu.psw.CF = 1; cpu.psw.ZF = 0; }
        else { cpu.psw.CF = 0; cpu.psw.ZF = 1; }
        cpu.shrt = 1;
    }
};

#endif //VM7_COMPARE_H
