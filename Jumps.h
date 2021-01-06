//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_JUMPS_H
#define VM7_JUMPS_H

#include "Commands.h"

class Jump : public Jumps
{
    public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.currentCommand.cmd.r2 == 0b00001)
            cpu.psw.IP = cpu.currentCommand.address;
        else if (cpu.currentCommand.cmd.r2 == 0b00011)
            cpu.psw.IP = cpu.regs[cpu.currentCommand.cmd.r1].uinteger + cpu.currentCommand.address;
        cpu.shrt = 1;
    }
};

class JumpRelative : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        int i = 1;
        while (i < cpu.currentCommand.cmd.r2) i *= 10;
        cpu.psw.IP = cpu.currentCommand.cmd.r1 * i + cpu.currentCommand.cmd.r2;
        cpu.shrt = 0;
    }
};

class JumpIndirect : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.psw.IP = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        cpu.shrt = 0;
    }
};

class Je : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 1)
            cpu.psw.IP = cpu.currentCommand.address;
    }
};

class Jg : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 0 && cpu.psw.SF == cpu.psw.OF)
            cpu.psw.IP = cpu.currentCommand.address;
    }
};

class Jl : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 0 && cpu.psw.SF != cpu.psw.OF)
            cpu.psw.IP = cpu.currentCommand.address;
    }
};

class Ja : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 0 && cpu.psw.CF == 0)
            cpu.psw.IP = cpu.currentCommand.address;
        cpu.shrt = 0;
    }
};

class Jb : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.CF == 1)
            cpu.psw.IP = cpu.currentCommand.address;
        cpu.shrt = 0;
    }
};

class Call : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.regs[cpu.currentCommand.cmd.r1] = cpu.regs[cpu.currentCommand.cmd.r2];
        cpu.psw.IP = cpu.currentCommand.address;
        cpu.shrt = 0;
    }
};

class Return : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.psw.IP = cpu.currentCommand.cmd.r1;
        cpu.shrt = 1;
    }
};
#endif //VM7_JUMPS_H
