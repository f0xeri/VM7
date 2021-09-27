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
        cpu.shrt = 0;
        cpu.ipch = 1;
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
        cpu.ipch = 1;
    }
};

class JumpIndirect : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.psw.IP = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        cpu.shrt = 0;
        cpu.ipch = 1;
    }
};

class Je : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 1)
        {
            cpu.psw.IP = cpu.currentCommand.address;
            cpu.ipch = 1;
        }
        cpu.shrt = 0;
    }
};

class Jg : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 0 && cpu.psw.SF == cpu.psw.OF)
        {
            cpu.psw.IP = cpu.currentCommand.address;
            cpu.ipch = 1;
        }
        cpu.shrt = 0;

    }
};

class Jl : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 0 && cpu.psw.SF != cpu.psw.OF)
        {
            cpu.psw.IP = cpu.currentCommand.address;
            cpu.ipch = 1;
        }
        cpu.shrt = 0;
    }
};

class Ja : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.ZF == 0 && cpu.psw.CF == 0)
        {
            cpu.psw.IP = cpu.currentCommand.address;
            cpu.ipch = 1;
        }
        cpu.shrt = 0;
    }
};

class Jb : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        if (cpu.psw.CF == 1)
        {
            cpu.psw.IP = cpu.currentCommand.address;
            cpu.ipch = 1;
        }
        cpu.shrt = 0;
    }
};

class Call : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.regs[cpu.currentCommand.cmd.r1].uinteger = cpu.psw.IP;
        cpu.psw.IP = cpu.currentCommand.address;
        cpu.shrt = 0;
        cpu.ipch = 1;
    }
};

class Return : public Jumps
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.psw.IP = cpu.regs[cpu.currentCommand.cmd.r1].uinteger;
        cpu.shrt = 1;
        cpu.ipch = 0;
    }
};
#endif //VM7_JUMPS_H
