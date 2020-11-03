//
// Created by Yaroslav on 03.11.2020.
//

#ifndef VM7_REALMATH_H
#define VM7_REALMATH_H

#include "Commands.h"

class RealMath : public Math
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override {};
};

class RealAddRR : public RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real + regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class RealSubRR : public RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real - regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class RealMulRR : public RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real * regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class RealDivRR : public RealMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.real = regs.grp.GetData(regs.currentCommand.cmd.r1).real / regs.grp.GetData(regs.currentCommand.cmd.r2).real;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};
#endif //VM7_REALMATH_H
