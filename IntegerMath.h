//
// Created by Yaroslav on 02.11.2020.
//

#ifndef VM7_INTEGERMATH_H
#define VM7_INTEGERMATH_H

#include "Commands.h"

class IntegerMath : public Math
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override {};
};

class IntAddRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2,data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer + regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};

class IntSubRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer - regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};

class IntMulRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer * regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};

class IntDivRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer / regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};
/**********************************************************************************************************************/

class UIntegerMath : public Math
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override {};
};

class UIntAddRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger + regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class UIntSubRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger - regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class UIntMulRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger * regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class UIntDivRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger / regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

#endif //VM7_INTEGERMATH_H
