#include <iostream>
#include "Processor.h"
#include "Commands.h"
#include "Registers.h"

int main()
{
    // r1 - dest, r2 - source
    Processor cpu;
    MemUnion lsm{};
    lsm.cmd32.cmd.opcode = cpu.ldstr;             // лоад стринг
    lsm.cmd32.cmd.r1 = 5;                         // размер строки в р1
    lsm.cmd32.cmd.r2  = 0;                        // мусор
    lsm.cmd32.address = 50000;                    // адрес в памяти куда грузим строку
    cpu.memory.LoadData(0, lsm, sizeof(lsm));

    MemUnion psm{};
    psm.cmd32.cmd.opcode = cpu.prtstr;             // вывод строки
    psm.cmd32.cmd.r1 = 0;                          // мусор
    psm.cmd32.cmd.r2  = 5;                         // размер строки
    psm.cmd32.address = 50000;                     // адрес откуда берём строку
    cpu.memory.LoadData(sizeof(MemUnion), psm, sizeof(psm));
    cpu.Run();
    return 0;
}
