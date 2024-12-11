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

    // Start inline test Program
    memory[0xFFFC] = CPU::INS_JSR;
    memory[0xFFFD] = 0x42;
    memory[0xFFFE] = 0x42;
    memory[0x4242] = CPU::INS_LDA_IM;
    memory[0x4243] = 0x84;
    // End inline test Program

    cpu.Execute(9, memory);
    std::cout << "Done!" << std::endl;
    return 0;
}