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

class Command
{
protected:
    unsigned short GetAddress(const Registers &regs) const noexcept
    {
        return regs.currentCommand.address;
    }
public:
    virtual void operator()(Memory &mem, Registers &regs) const noexcept = 0;
};

class Stop : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override {}
};

// in type 0 address
// in 1 0 32000
class Input : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
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
        mem.LoadData(regs.currentCommand.address, temp);
    }
};

class Output : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        auto type = regs.currentCommand.cmd.r1;
        switch (type)
        {
            case 0:
                std::cout << mem.GetData(regs.currentCommand.address).integer << std::endl;
                break;
            case 1:
                std::cout << mem.GetData(regs.currentCommand.address).uinteger << std::endl;
                break;
            case 2:
                std::cout << mem.GetData(regs.currentCommand.address).real << std::endl;
                break;
        }
    }
};

class Math : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override {}
};

class Move : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override {}
};

class Compare : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override {}
};

class BinaryOperations : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override {}
};

class Jumps : public Command
{
    public: void operator()(Memory &mem, Registers &regs) const noexcept override {}
};
/**********************************************************************************************************************/
/* тут строки */
/*class LoadString : public Command
{
public:
    void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        std::string temp{};
        std::cout << std::endl;
        std::cin >> temp;

        data strSz{};
        strSz.integer = static_cast<int>(temp.size());
        regs.grp.LoadData(regs.currentCommand.cmd.r1, strSz);
        unsigned short loadAddress = GetAddress(regs);
        for (int i = 0; i < strSz.integer; ++i)
            mem.LoadData(i + loadAddress, data{temp[i]});
    }
};

class PrintString : public Command
{
public:
    void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        unsigned short printAddress = GetAddress(regs);
        data strSz{};
        strSz = regs.grp.GetData(regs.currentCommand.cmd.r2);
        for (int i = 0; i < strSz.integer; ++i)
            std::cout << (char)mem.GetData(i + printAddress).integer;
    }
};*/
#endif //VM7_COMMANDS_H
