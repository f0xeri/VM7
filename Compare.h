//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_COMPARE_H
#define VM7_COMPARE_H

#include <cfenv>
#include "Commands.h"

class IntegerCompare : public Compare
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        int temp = 0;
        if (__builtin_sub_overflow(regs.grp.GetData(regs.currentCommand.cmd.r1).integer, regs.grp.GetData(regs.currentCommand.cmd.r2).integer, &temp))
            regs.psw.OF = 1;
        else regs.psw.OF = 0;
        if (regs.grp.GetData(regs.currentCommand.cmd.r1).integer == regs.grp.GetData(regs.currentCommand.cmd.r2).integer)
        {
            regs.psw.ZF = 1;
            regs.psw.SF = 0;
            regs.psw.CF = 0;
        }
        else if (regs.grp.GetData(regs.currentCommand.cmd.r1).integer < regs.grp.GetData(regs.currentCommand.cmd.r2).integer)
        {
            regs.psw.ZF = 0;
            regs.psw.SF = 1;
            regs.psw.CF = 1;
        }
        else
        {
            regs.psw.ZF = 0;
            regs.psw.SF = 0;
            regs.psw.CF = 0;
        }
    }
};

class UIntegerCompare : public Compare
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        unsigned int temp = 0;
        if (__builtin_sub_overflow(regs.grp.GetData(regs.currentCommand.cmd.r1).integer, regs.grp.GetData(regs.currentCommand.cmd.r2).integer, &temp))
            regs.psw.OF = 1;
        else regs.psw.OF = 0;
        if (regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger == regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger)
        {
            regs.psw.ZF = 1;
            regs.psw.SF = 0;
            regs.psw.CF = 0;
        }
        else if (regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger < regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger)
        {
            regs.psw.ZF = 0;
            regs.psw.SF = 1;
            regs.psw.CF = 1;
        }
        else
        {
            regs.psw.ZF = 0;
            regs.psw.SF = 0;
            regs.psw.CF = 0;
        }
    }
};

class RealCompare : public Compare
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        std::feclearexcept(FE_OVERFLOW);
        auto temp = regs.grp.GetData(regs.currentCommand.cmd.r1).real - regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        if ((bool)std::fetestexcept(FE_OVERFLOW))
            regs.psw.OF = 1;
        else regs.psw.OF = 0;
        if ((regs.grp.GetData(regs.currentCommand.cmd.r1).real - regs.grp.GetData(regs.currentCommand.cmd.r2).real) < std::numeric_limits<float>::epsilon())
        {
            regs.psw.ZF = 1;
            regs.psw.SF = 0;
            regs.psw.CF = 0;
        }
        else if (regs.grp.GetData(regs.currentCommand.cmd.r1).real < regs.grp.GetData(regs.currentCommand.cmd.r2).real)
        {
            regs.psw.ZF = 0;
            regs.psw.SF = 1;
            regs.psw.CF = 1;
        }
        else
        {
            regs.psw.ZF = 0;
            regs.psw.SF = 0;
            regs.psw.CF = 0;
        }
    }
};

#endif //VM7_COMPARE_H
