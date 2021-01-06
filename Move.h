//
// Created by Yaroslav on 03.11.2020.
//

#ifndef VM7_MOVE_H
#define VM7_MOVE_H

#include "Commands.h"

class MoveRR : public Move
{
    public: void operator()(Processor &cpu) noexcept override
    {
        cpu.regs[cpu.currentCommand.cmd.r1] = cpu.regs[cpu.currentCommand.cmd.r2];
        cpu.shrt = 0;
    }
};

class MoveRS : public Move
{
    public: void operator()(Processor &cpu) noexcept override
    {
        cpu.regs[cpu.currentCommand.cmd.r1] = cpu.memory[cpu.currentCommand.address].data_;
        cpu.shrt = 0;
    }
};

class MoveSR : public Move
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.memory[cpu.currentCommand.address] = word{cpu.regs[cpu.currentCommand.cmd.r1]};
        cpu.shrt = 0;
    }
};

class LoadRegister : public Move
{
public: void operator()(Processor &cpu) noexcept override
    {
        cpu.regs[cpu.currentCommand.cmd.r1] = data{cpu.currentCommand.address};
        cpu.shrt = 0;
    }
};

#endif //VM7_MOVE_H
