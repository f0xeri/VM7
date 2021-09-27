#include "Processor.h"
#include "Loader.h"

int main(int argc, char *argv[])
{
    Processor cpu;
    Load(argv[1], cpu);
    cpu.Run();
    return 0;
}
