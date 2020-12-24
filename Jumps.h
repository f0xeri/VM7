//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_JUMPS_H
#define VM7_JUMPS_H

#include "Commands.h"

class Jump : public Jumps
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        if (regs.currentCommand.cmd.r2 == 0b00001)
            psw.IP = regs.currentCommand.address;
        else if (regs.currentCommand.cmd.r2 == 0b00011)
            psw.IP = regs[regs.currentCommand.cmd.r1].uinteger + regs.currentCommand.address;
        psw.SH = 1;
    }
};

class JumpRelative : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        int i = 1;
        while (i < regs.currentCommand.cmd.r2) i *= 10;
        psw.IP = regs.currentCommand.cmd.r1 * i + regs.currentCommand.cmd.r2;
        psw.SH = 0;
    }
};

class JumpIndirect : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        psw.IP = regs[regs.currentCommand.cmd.r1].uinteger;
        psw.SH = 0;
    }
};

class Je : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        if (psw.ZF == 1)
            psw.IP = regs.currentCommand.address;
    }
};

class Jg : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        if (psw.ZF == 0 && psw.SF == psw.OF)
            psw.IP = regs.currentCommand.address;
    }
};

class Jl : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        if (psw.ZF == 0 && psw.SF != psw.OF)
            psw.IP = regs.currentCommand.address;
    }
};

class Ja : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        if (psw.ZF == 0 && psw.CF == 0)
            psw.IP = regs.currentCommand.address;
        psw.SH = 0;
    }
};

class Jb : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        if (psw.CF == 1)
            psw.IP = regs.currentCommand.address;
        psw.SH = 0;
    }
};

class Call : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r1] = regs[regs.currentCommand.cmd.r2];
        psw.IP = regs.currentCommand.address;
        psw.SH = 0;
    }
};

class Return : public Jumps
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        psw.IP = regs.currentCommand.cmd.r1;
        psw.SH = 1;
    }
};
#endif //VM7_JUMPS_H
