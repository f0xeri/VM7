#include "Processor.h"
#include "Loader.h"

int main()
{
    Processor cpu;
    Load("test.txt", cpu);
    cpu.Run();
    return 0;
}
