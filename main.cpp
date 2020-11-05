#include "Processor.h"
#include "Loader.h"

int main()
{
    Processor cpu;
    Load("test2.txt", cpu);
    cpu.Run();
    return 0;
}
