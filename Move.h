//
// Created by Yaroslav on 03.11.2020.
//

#ifndef VM7_MOVE_H
#define VM7_MOVE_H

#include "Commands.h"

class MoveRR : public Move
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r1, regs.grp.GetData(regs.currentCommand.cmd.r2));
    }
};

class MoveRS : public Move
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        regs.grp.LoadData(regs.currentCommand.cmd.r1, mem.GetData(regs.currentCommand.address));
    }
};

#endif //VM7_MOVE_H
