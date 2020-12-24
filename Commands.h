//
// Created by Yaroslav on 05.09.2020.
//

#ifndef VM7_COMMANDS_H
#define VM7_COMMANDS_H

#include <string>
#include <iostream>
#include "Types.h"
#include "Memory.h"
#include "Registers.h"
#include "PSW.h"
#include "Processor.h"

class Processor;

class Command
{

public:
    virtual void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept = 0;
    //virtual int size() const noexcept = 0;
};

class Stop : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {}
};

// in type 0 address
// in 1 0 32000
class Input : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto type = regs.currentCommand.cmd.r1;
        data temp{};
        switch (type)
        {
            case 0:
                std::cin >> temp.integer;
                break;
            case 1:
                std::cin >> temp.uinteger;
                break;
            case 2:
                std::cin >> temp.real;
                break;
        }
        mem[regs.currentCommand.address] = word{temp};
        psw.SH = 0;
    }
};

class Output : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override
    {
        auto type = regs.currentCommand.cmd.r1;
        switch (type)
        {
            case 0:
                std::cout << mem[regs.currentCommand.address].data_.integer << std::endl;
                break;
            case 1:
                std::cout << mem[regs.currentCommand.address].data_.uinteger << std::endl;
                break;
            case 2:
                std::cout << mem[regs.currentCommand.address].data_.real << std::endl;
                break;
        }
        psw.SH = 0;
    }
};

class Math : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {}
};

class Move : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {}
};

class Compare : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {}
};

class BinaryOperations : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {}
};

class Jumps : public Command
{
    public: void operator()(PSW &psw, Memory &mem, Registers &regs) const noexcept override {}
};

#endif //VM7_COMMANDS_H
