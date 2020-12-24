//
// Created by Yaroslav on 04.11.2020.
//

#ifndef VM7_BINARYOPERATIONS_H
#define VM7_BINARYOPERATIONS_H

#include "Commands.h"

class And : public BinaryOperations
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs[regs.currentCommand.cmd.r1].integer & regs[regs.currentCommand.cmd.r2].integer;
        regs[regs.currentCommand.cmd.r2] = data{res};
    }
};

class Or : public BinaryOperations
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs[regs.currentCommand.cmd.r1].integer | regs[regs.currentCommand.cmd.r2].integer;
        regs[regs.currentCommand.cmd.r2] = data{res};
    }
};

class Xor : public BinaryOperations
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs[regs.currentCommand.cmd.r1].integer ^ regs[regs.currentCommand.cmd.r2].integer;
        regs[regs.currentCommand.cmd.r2] = data{res};
    }
};

class ShiftL : public BinaryOperations
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs[regs.currentCommand.cmd.r1].integer << regs[regs.currentCommand.cmd.r2].integer;
        regs[regs.currentCommand.cmd.r2] = data{res};
    }
};

class ShiftR : public  BinaryOperations
{
public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto res = regs[regs.currentCommand.cmd.r1].integer >> regs[regs.currentCommand.cmd.r2].integer;
        regs[regs.currentCommand.cmd.r2] = data{res};
    }
};
#endif //VM7_BINARYOPERATIONS_H
