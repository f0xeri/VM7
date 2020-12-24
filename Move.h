//
// Created by Yaroslav on 03.11.2020.
//

#ifndef VM7_MOVE_H
#define VM7_MOVE_H

#include "Commands.h"

class MoveRR : public Move
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r1] = regs[regs.currentCommand.cmd.r2];
        psw.SH = 0;
    }
};

class MoveRS : public Move
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r1] = mem[regs.currentCommand.address].data_;
        psw.SH = 0;
    }
};

class MoveSR : public Move
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        mem[regs.currentCommand.address] = word{regs[regs.currentCommand.cmd.r1]};
        psw.SH = 0;
    }
};

class LoadRegister : public Move
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        regs[regs.currentCommand.cmd.r1] = data{regs.currentCommand.address};
        psw.SH = 0;
    }
};

#endif //VM7_MOVE_H
