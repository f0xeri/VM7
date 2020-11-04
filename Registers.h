//
// Created by Yaroslav on 16.10.2020.
//

#ifndef VM7_REGISTERS_H
#define VM7_REGISTERS_H


#include <cstdint>
#include <exception>
#include "Types.h"

class Registers
{
public:
    class PSW
    {
    public:
        unsigned short IP;
        unsigned short CF;      // флаг переноса
        unsigned short ZF;      // флаг нуля
        unsigned short SF;      // флаг знака
        unsigned short OF;      // флаг overflow
        unsigned short IF;      // флаг разрешения прерываний

        PSW() : IP(0), CF(0), ZF(0), SF(0), IF(1) {}

        void resetFlags() noexcept { ZF = 0; CF = 0; SF = 0; IF = 1; }
    } psw{};

// РОН
class GRP
{
    int32_t grp[32]{};
    class RegisterNotExists : std::exception{};
    public:
        void LoadData(uint8_t grpNumber, const data &dat)
        {
            grpNumber >= 32 ? throw RegisterNotExists() : grp[grpNumber] = dat.integer;
        };
        data GetData(uint8_t grpNumber)
        {
            if (grpNumber >= 32) throw RegisterNotExists();
            return data{grp[grpNumber]};
        };
    } grp{};
    command32 currentCommand{};
};


#endif //VM7_REGISTERS_H
