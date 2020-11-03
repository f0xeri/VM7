//
// Created by Yaroslav on 05.09.2020.
//

#include <cstring>
#include "Processor.h"
#include "IntegerMath.h"
#include "RealMath.h"
#include "Move.h"

Processor::Processor()
{
    InitCommands();
}

void Processor::Run()
{
    while (regs.psw.IF != 0)
    {
        auto currentCmd = GetCommand(memory, regs.psw.IP);
        regs.currentCommand = currentCmd;
        if (currentCmd.cmd.opcode)
            commands[currentCmd.cmd.opcode]->operator()(memory, regs);
        else
            regs.psw.IF = 0;
        regs.psw.IP += 1; // sizeof(MemUnion) / 4
    }
}

void Processor::SetIP(unsigned short address)
{
    regs.psw.IP = address;
}

void Processor::InitCommands()
{
    commands.assign(128, nullptr);
    commands[stop] = new Stop();

    commands[iadd] = new IntAddRR();
    commands[isub] = new IntSubRR();
    commands[imul] = new IntMulRR();
    commands[idiv] = new IntDivRR();
    commands[imod] = new IntModRR();

    commands[uiadd] = new UIntAddRR();
    commands[uisub] = new UIntSubRR();
    commands[uimul] = new UIntMulRR();
    commands[uidiv] = new UIntDivRR();
    commands[uimod] = new UIntModRR();

    commands[radd] = new RealAddRR();
    commands[rsub] = new RealSubRR();
    commands[rmul] = new RealMulRR();
    commands[rdiv] = new RealDivRR();

    commands[movrr] = new MoveRR();
    commands[movrs] = new MoveRS();
    //commands[ldstr] = new LoadString();
    //commands[prtstr] = new PrintString();
}

command16 Processor::GetCommand16(const Memory &mem, unsigned char address)
{
    MemUnion dat{};
    std::memcpy(&dat.bytes, &mem.memory[address], 4);
    return dat.cmd16;
}

command32 Processor::GetCommand(const Memory &mem, unsigned char address) {
    MemUnion dat{};
    std::memcpy(&dat.bytes, &mem.memory[address], 4);
    return dat.cmd32;
}
