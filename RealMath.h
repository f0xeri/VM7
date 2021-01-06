//
// Created by Yaroslav on 03.11.2020.
//

#ifndef VM7_REALMATH_H
#define VM7_REALMATH_H

#include "Commands.h"

class RealMath : public Math {};

class RealAddRR : public RealMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        data temp{};
        temp.real = cpu.regs[cpu.currentCommand.cmd.r1].real + cpu.regs[cpu.currentCommand.cmd.r2].real;
        cpu.regs[cpu.currentCommand.cmd.r2] = temp;
        cpu.shrt = 1;
    }
};

class RealSubRR : public RealMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        data temp{};
        temp.real = cpu.regs[cpu.currentCommand.cmd.r1].real - cpu.regs[cpu.currentCommand.cmd.r2].real;
        cpu.regs[cpu.currentCommand.cmd.r2] = temp;
        cpu.shrt = 1;
    }
};

class RealMulRR : public RealMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        data temp{};
        temp.real = cpu.regs[cpu.currentCommand.cmd.r1].real * cpu.regs[cpu.currentCommand.cmd.r2].real;
        cpu.regs[cpu.currentCommand.cmd.r2] = temp;
        cpu.shrt = 1;
    }
};

class RealDivRR : public RealMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        data temp{};
        temp.real = cpu.regs[cpu.currentCommand.cmd.r1].real / cpu.regs[cpu.currentCommand.cmd.r2].real;
        cpu.regs[cpu.currentCommand.cmd.r2] = temp;
        cpu.shrt = 1;
    }
};
#endif //VM7_REALMATH_H
