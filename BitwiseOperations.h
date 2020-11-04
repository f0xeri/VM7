//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_BITWISEOPERATIONS_H
#define VM7_BITWISEOPERATIONS_H

#include "Commands.h"

class And : public BitwiseOperations
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs.grp.GetData(regs.currentCommand.cmd.r1).integer & regs.grp.GetData(regs.currentCommand.cmd.r2).integer;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{res});
    }
};

class Or : public BitwiseOperations
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs.grp.GetData(regs.currentCommand.cmd.r1).integer | regs.grp.GetData(regs.currentCommand.cmd.r2).integer;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{res});
    }
};

class Xor : public BitwiseOperations
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs.grp.GetData(regs.currentCommand.cmd.r1).integer ^ regs.grp.GetData(regs.currentCommand.cmd.r2).integer;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{res});
    }
};

class ShiftL : public BitwiseOperations
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs.grp.GetData(regs.currentCommand.cmd.r1).integer << regs.grp.GetData(regs.currentCommand.cmd.r2).integer;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{res});
    }
};

class ShiftR : public  BitwiseOperations
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs.grp.GetData(regs.currentCommand.cmd.r1).integer >> regs.grp.GetData(regs.currentCommand.cmd.r2).integer;
        regs.grp.LoadData(regs.currentCommand.cmd.r2, data{res});
    }
};
#endif //VM7_BITWISEOPERATIONS_H
