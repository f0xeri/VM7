#include <iostream>
#include "Processor.h"
#include "Commands.h"
#include "Registers.h"

int main()
{
    Processor cpu;
    LoadString ls;
    PrintString ps;

    MemUnion lsm{};
    lsm.cmd32.cmd.opcode = cpu.ldstr;
    lsm.cmd32.cmd.r1 = 0;
    lsm.cmd32.cmd.r2  = 0;
    lsm.cmd32.address = 50000;
    cpu.memory.LoadData(0, lsm, sizeof(lsm));

    MemUnion psm{};
    lsm.cmd32.cmd.opcode = cpu.prtstr;
    lsm.cmd32.cmd.r1 = 0;
    lsm.cmd32.cmd.r2  = 0;
    lsm.cmd32.address = 50000;
    cpu.memory.LoadData(sizeof(MemUnion), psm, sizeof(psm));

    cpu.Run();
    return 0;
}
