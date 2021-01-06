//
// Created by Yaroslav on 02.11.2020.
//

#ifndef VM7_INTEGERMATH_H
#define VM7_INTEGERMATH_H

#include "Commands.h"

class IntegerMath : public Math
{
protected: void setFlags(Processor &cpu, int32_t op1, int32_t op2, uint64_t res)
    {
        res > std::numeric_limits<uint32_t>::max() ? cpu.psw.CF = true : cpu.psw.CF = false;
        bool op1sign = op1 < 0;
        bool op2sign = op2 < 0;
        bool ressign = cpu.regs[cpu.currentCommand.cmd.r2].integer < 0;

        if ((op1sign and op2sign and not ressign) or (not op1sign and not op2sign and ressign))
        {
            cpu.psw.OF = true;
        }
        else
        {
            cpu.psw.OF = false;
        }

        if (res == 0)
        {
            cpu.psw.ZF = true;
        }
        else
        {
            cpu.psw.ZF = false;
        }
    };
};

class IntAddRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].integer;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].integer;
        uint64_t res = op1 + op2;
        cpu.regs[cpu.currentCommand.cmd.r2].integer = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class IntSubRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].integer;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].integer;
        uint64_t res = op1 - op2;
        cpu.regs[cpu.currentCommand.cmd.r2].integer = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class IntMulRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].integer;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].integer;
        uint64_t res = op1 * op2;
        cpu.regs[cpu.currentCommand.cmd.r2].integer = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class IntDivRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].integer;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].integer;
        uint64_t res = op1 / op2;
        cpu.regs[cpu.currentCommand.cmd.r2].integer = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class IntModRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].integer;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].integer;
        uint64_t res = op1 % op2;
        cpu.regs[cpu.currentCommand.cmd.r2].integer = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};
/**********************************************************************************************************************/

class UIntegerMath : public Math
{
public: void operator()(Processor &cpu) noexcept override {};
};

class UIntAddRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].uinteger;
        uint64_t res = op1 + op2;
        cpu.regs[cpu.currentCommand.cmd.r2].uinteger = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class UIntSubRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].uinteger;
        uint64_t res = op1 - op2;
        cpu.regs[cpu.currentCommand.cmd.r2].uinteger = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class UIntMulRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].uinteger;
        uint64_t res = op1 * op2;
        cpu.regs[cpu.currentCommand.cmd.r2].uinteger = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class UIntDivRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].uinteger;
        uint64_t res = op1 / op2;
        cpu.regs[cpu.currentCommand.cmd.r2].uinteger = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

class UIntModRR : public IntegerMath
{
public: void operator()(Processor &cpu) noexcept override
    {
        int32_t op1 = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        int32_t op2 = cpu.regs[cpu.currentCommand.cmd.r2].uinteger;
        uint64_t res = op1 % op2;
        cpu.regs[cpu.currentCommand.cmd.r2].uinteger = res;
        setFlags(cpu, op1, op2, res);
        cpu.shrt = 1;
    }
};

#endif //VM7_INTEGERMATH_H
