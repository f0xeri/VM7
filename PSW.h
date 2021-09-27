//
// Created by Yaroslav on 24.12.2020.
//

#ifndef VM7_PSW_H
#define VM7_PSW_H

class PSW
{
public:
    unsigned short IP;
    bool CF;      // флаг переноса
    bool ZF;      // флаг нуля
    bool SF;      // флаг знака
    bool OF;      // флаг overflow

    PSW() : IP(0), CF(0), ZF(0), SF(0){}

    void resetFlags() noexcept { ZF = 0; CF = 0; SF = 0; OF = 0; }
};

#endif //VM7_PSW_H
