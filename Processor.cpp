//
// Created by Yaroslav on 05.09.2020.
//

#include <cstring>
#include "Processor.h"
#include "IntegerMath.h"
#include "RealMath.h"
#include "Move.h"
#include "Compare.h"
#include "BinaryOperations.h"
#include "Jumps.h"

Processor::Processor()
{
    InitCommands();
}

void Processor::Run()
{
    while (psw.IF != 0)
    {
        auto currentCmd = memory[psw.IP];
        regs.currentCommand = currentCmd.cmd32;
        if (currentCmd.cmd32.cmd.opcode)
        {
            commands[currentCmd.cmd32.cmd.opcode]->operator()(psw, memory, regs);
            if (psw.SH == 1)
                if (currentCmd.cmd16[1].opcode)
                    commands[currentCmd.cmd16[1].opcode]->operator()(psw, memory, regs);
        }
        else
            psw.IF = 0;
        psw.IP += 1; // sizeof(word) / 4
    }
}

void Processor::SetIP(unsigned short address)
{
    psw.IP = address;
}

void Processor::InitCommands()
{
    commands.assign(128, nullptr);

    commands[in] = new Input();
    commands[out] = new Output();
    commands[icmp] = new IntegerCompare();
    commands[uicmp] = new UIntegerCompare();
    commands[rcmp] = new RealCompare();

    commands[iadd] = new IntAddRR();
    commands[uiadd] = new UIntAddRR();
    commands[radd] = new RealAddRR();

    commands[isub] = new IntSubRR();
    commands[uisub] = new UIntSubRR();
    commands[rsub] = new RealSubRR();

    commands[imul] = new IntMulRR();
    commands[uimul] = new UIntMulRR();
    commands[rmul] = new RealMulRR();

    commands[idiv] = new IntDivRR();
    commands[uidiv] = new UIntDivRR();
    commands[rdiv] = new RealDivRR();
    commands[imod] = new IntModRR();
    commands[uimod] = new UIntModRR();

    commands[movrr] = new MoveRR();
    commands[movrs] = new MoveRS();
    commands[movsr] = new MoveSR();
    commands[loadr] = new LoadRegister();

    commands[_and] = new And();
    commands[_or] = new Or();
    commands[_xor] = new Xor();
    commands[shiftl] = new ShiftL();
    commands[shiftr] = new ShiftR();

    commands[jmp] = new Jump();
    commands[jmpr] = new JumpRelative();
    commands[jmpi] = new JumpIndirect();
    commands[je] = new Je();
    commands[jg] = new Jg();
    commands[jl] = new Jl();
    commands[ja] = new Ja();
    commands[jb] = new Jb();
    commands[call] = new Call();
    commands[ret] = new Return();

    commands[stop] = new Stop();
}

