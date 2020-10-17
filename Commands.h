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

class LoadString : public Command
{
public:
    void operator()(Memory &mem, Registers &regs) const noexcept override
    {
        std::string temp{};
        std::cout << std::endl;
        std::cin >> temp;

        data strSz{};
        strSz.integer = static_cast<int>(temp.size());
        unsigned short loadAddress = GetAddress(regs);
        mem.LoadData(loadAddress, strSz);
        loadAddress += sizeof(strSz);
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
        data strSz{mem.GetData(printAddress)};
        printAddress += sizeof(strSz);
        for (int i = 0; i < strSz.integer; ++i)
            std::cout << (char)mem.GetData(i + printAddress).integer;
    }
};
#endif //VM7_COMMANDS_H
