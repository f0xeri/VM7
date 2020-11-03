//
// Created by Yaroslav on 03.11.2020.
//

#ifndef VM7_REAL_H
#define VM7_REAL_H

#include "Commands.h"

class RealMath : Math
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override {};
};

class RealAddRR : RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real + regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class RealSubRR : RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real - regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class RealMulRR : RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real * regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class RealDivRR : RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real / regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};
#endif //VM7_REAL_H
