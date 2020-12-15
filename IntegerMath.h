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
        regs.psw.SH = 1;
    }
};

class IntSubRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer - regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
        regs.psw.SH = 1;
    }
};

class IntMulRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer * regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
        regs.psw.SH = 1;
    }
};

class IntDivRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer / regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
        regs.psw.SH = 1;
    }
};

class IntModRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{regs.grp.GetData(regs.currentCommand.cmd.r1).integer % regs.grp.GetData(regs.currentCommand.cmd.r2).integer});
        regs.psw.SH = 1;
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
        regs.psw.SH = 1;
    }
};

class UIntSubRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger - regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
        regs.psw.SH = 1;
    }
};

class UIntMulRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger * regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
        regs.psw.SH = 1;
    }
};

class UIntDivRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger / regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
        regs.psw.SH = 1;
    }
};

class UIntModRR : public IntegerMath
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        data temp{};
        temp.uinteger = regs.grp.GetData(regs.currentCommand.cmd.r1).uinteger % regs.grp.GetData(regs.currentCommand.cmd.r2).uinteger;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, temp);
        regs.psw.SH = 1;
    }
};

#endif //VM7_INTEGERMATH_H
