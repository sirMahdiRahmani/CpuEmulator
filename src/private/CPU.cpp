#include "CPU.h"

void CPU::Reset(RAM &memory)
{
    PC = 0xFFFC;
    SP = 0x0100;
    C = Z = I = D = B = V = N = 0;
    A = X = Y = 0;
    memory.Initialize();
}

Byte CPU::FetchByte(u32 &cycles, RAM &memory)
{
    Byte data = memory[PC];
    PC++;
    cycles--;
    return data;
}

void CPU::Execute(u32 cycles, RAM &memory)
{
    while (cycles > 0)
    {
        Byte instruction = FetchByte(cycles, memory);
        switch (instruction)
        {
        case INS_LDA_IM:
        {
            Byte Value = FetchByte(cycles, memory);
            A = Value;
            Z = (A == 0);
            N = (A & 0b10000000) > 0;
        }
        break;

        default:
            break;
        }
    }
}
