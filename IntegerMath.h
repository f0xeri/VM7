//
// Created by Yaroslav on 02.11.2020.
//

#ifndef VM7_INTEGERMATH_H
#define VM7_INTEGERMATH_H

#include "Commands.h"

class IntegerMath : public Math
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {};
};

class IntAddRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r2] = data{regs[regs.currentCommand.cmd.r1].integer + regs[regs.currentCommand.cmd.r2].integer};
        psw.SH = 1;
    }
};

class IntSubRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r2] = data{regs[regs.currentCommand.cmd.r1].integer - regs[regs.currentCommand.cmd.r2].integer};
        psw.SH = 1;
    }
};

class IntMulRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r2] = data{regs[regs.currentCommand.cmd.r1].integer * regs[regs.currentCommand.cmd.r2].integer};
        psw.SH = 1;
    }
};

class IntDivRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r2] = data{regs[regs.currentCommand.cmd.r1].integer / regs[regs.currentCommand.cmd.r2].integer};
        psw.SH = 1;
    }
};

class IntModRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r2] = data{regs[regs.currentCommand.cmd.r1].integer % regs[regs.currentCommand.cmd.r2].integer};
        psw.SH = 1;
    }
};
/**********************************************************************************************************************/

class UIntegerMath : public Math
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {};
};

class UIntAddRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs[regs.currentCommand.cmd.r1].uinteger + regs[regs.currentCommand.cmd.r2].uinteger;
        regs[regs.currentCommand.cmd.r2] =  temp;
        psw.SH = 1;
    }
};

class UIntSubRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs[regs.currentCommand.cmd.r1].uinteger - regs[regs.currentCommand.cmd.r2].uinteger;
        regs[regs.currentCommand.cmd.r2] =  temp;
        psw.SH = 1;
    }
};

class UIntMulRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs[regs.currentCommand.cmd.r1].uinteger * regs[regs.currentCommand.cmd.r2].uinteger;
        regs[regs.currentCommand.cmd.r2] =  temp;
        psw.SH = 1;
    }
};

class UIntDivRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs[regs.currentCommand.cmd.r1].uinteger / regs[regs.currentCommand.cmd.r2].uinteger;
        regs[regs.currentCommand.cmd.r2] =  temp;
        psw.SH = 1;
    }
};

class UIntModRR : public IntegerMath
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs[regs.currentCommand.cmd.r1].uinteger % regs[regs.currentCommand.cmd.r2].uinteger;
        regs[regs.currentCommand.cmd.r2] =  temp;
        psw.SH = 1;
    }
};

#endif //VM7_INTEGERMATH_H
