//
// Created by Yaroslav on 02.11.2020.
//

#ifndef VM7_INTEGERMATH_H
#define VM7_INTEGERMATH_H

#include "Commands.h"

class IntegerMath : Math
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override {};
};

class IntAddRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2,data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer + regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};

class IntSubRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer - regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};

class IntMulRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer * regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};

class IntDivRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer / regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
    }
};
/**********************************************************************************************************************/

class UIntegerMath : Math
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override {};
};

class UIntAddRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger + regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class UIntSubRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger - regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class UIntMulRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger * regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

class UIntDivRR : IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger / regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
    }
};

#endif //VM7_INTEGERMATH_H
