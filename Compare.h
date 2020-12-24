//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_COMPARE_H
#define VM7_COMPARE_H

#include <cfenv>
#include "Commands.h"

class IntegerCompare : public Compare
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        int temp = 0;
        if (__builtin_sub_overflow(regs[regs.currentCommand.cmd.r1].integer, regs[regs.currentCommand.cmd.r2].integer, &temp))
            psw.OF = 1;
        else psw.OF = 0;
        if (regs[regs.currentCommand.cmd.r1].integer == regs[regs.currentCommand.cmd.r2].integer)
        {
            psw.ZF = 1;
            psw.SF = 0;
            psw.CF = 0;
        }
        else if (regs[regs.currentCommand.cmd.r1].integer < regs[regs.currentCommand.cmd.r2].integer)
        {
            psw.ZF = 0;
            psw.SF = 1;
            psw.CF = 1;
        }
        else
        {
            psw.ZF = 0;
            psw.SF = 0;
            psw.CF = 0;
        }
        psw.SH = 1;
    }
};

class UIntegerCompare : public Compare
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        unsigned int temp = 0;
        if (__builtin_sub_overflow(regs[regs.currentCommand.cmd.r1].integer, regs[regs.currentCommand.cmd.r2].integer, &temp))
            psw.OF = 1;
        else psw.OF = 0;
        if (regs[regs.currentCommand.cmd.r1].uinteger == regs[regs.currentCommand.cmd.r2].uinteger)
        {
            psw.ZF = 1;
            psw.SF = 0;
            psw.CF = 0;
        }
        else if (regs[regs.currentCommand.cmd.r1].uinteger < regs[regs.currentCommand.cmd.r2].uinteger)
        {
            psw.ZF = 0;
            psw.SF = 1;
            psw.CF = 1;
        }
        else
        {
            psw.ZF = 0;
            psw.SF = 0;
            psw.CF = 0;
        }
        psw.SH = 1;
    }
};

class RealCompare : public Compare
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        std::feclearexcept(FE_OVERFLOW);
        auto temp = regs[regs.currentCommand.cmd.r1].real - regs[regs.currentCommand.cmd.r2].real;
        if ((bool)std::fetestexcept(FE_OVERFLOW))
            psw.OF = 1;
        else psw.OF = 0;
        if ((regs[regs.currentCommand.cmd.r1].real - regs[regs.currentCommand.cmd.r2].real) < std::numeric_limits<float>::epsilon())
        {
            psw.ZF = 1;
            psw.SF = 0;
            psw.CF = 0;
        }
        else if (regs[regs.currentCommand.cmd.r1].real < regs[regs.currentCommand.cmd.r2].real)
        {
            psw.ZF = 0;
            psw.SF = 1;
            psw.CF = 1;
        }
        else
        {
            psw.ZF = 0;
            psw.SF = 0;
            psw.CF = 0;
        }
        psw.SH = 1;
    }
};

#endif //VM7_COMPARE_H
