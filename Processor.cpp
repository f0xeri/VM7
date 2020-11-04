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
#include "Jump.h"

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

    commands[_and] = new And();
    commands[_or] = new Or();
    commands[_xor] = new Xor();
    commands[shiftl] = new ShiftL();
    commands[shiftr] = new ShiftR();

    commands[jmp] = new Jump();
    commands[je] = new Je();
    commands[jg] = new Jg();
    commands[jl] = new Jl();
    commands[ja] = new Ja();
    commands[jb] = new Jb();

    commands[stop] = new Stop();
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
