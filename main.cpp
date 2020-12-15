#include "Processor.h"
#include "Loader.h"

int main()
{
    Processor cpu;
    Load("program.txt", cpu);
    cpu.Run();
    return 0;
}
