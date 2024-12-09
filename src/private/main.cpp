#include <iostream>
#include "CPU.h"
#include "RAM.h"

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

int main()
{
    RAM memory;
    CPU cpu;
    cpu.Reset(memory);
    cpu.Execute(2, memory);
    std::cout << "Done!" << std::endl;
    return 0;
}