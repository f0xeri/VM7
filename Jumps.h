//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_JUMPS_H
#define VM7_JUMPS_H

#include "Commands.h"

class Jump : public Jumps
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.psw.IP = regs.currentCommand.address;
    }
};

class Je : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        if (regs.psw.ZF == 1)
            regs.psw.IP = regs.currentCommand.address;
    }
};

class Jg : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        if (regs.psw.ZF == 0 && regs.psw.SF == regs.psw.OF)
            regs.psw.IP = regs.currentCommand.address;
    }
};

class Jl : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        if (regs.psw.ZF == 0 && regs.psw.SF != regs.psw.OF)
            regs.psw.IP = regs.currentCommand.address;
    }
};

class Ja : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        if (regs.psw.ZF == 0 && regs.psw.CF == 0)
            regs.psw.IP = regs.currentCommand.address;
    }
};

class Jb : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        if (regs.psw.CF == 1)
            regs.psw.IP = regs.currentCommand.address;
    }
};

class Call : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r1, regs.grp.GetData(regs.currentCommand.cmd.r2));
        regs.psw.IP = regs.currentCommand.address;
    }
};

class Return : public Jumps
{
public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.psw.IP = regs.currentCommand.cmd.r1;
    }
};
#endif //VM7_JUMPS_H
