#include "CPU.h"
#include "stdio.h"

void CPU::Reset(RAM &memory)
{
	PC = 0xFFFC;
	SP = 0x0100;
	C = Z = I = D = B = V = N = 0;
	A = X = Y = 0;
	memory.Initialize();
}

void CPU::LDASetStatus()
{
	Z = (A == 0);
	N = (A & 0b10000000) > 0;
}

Byte CPU::FetchByte(u32 &cycles, RAM &memory)
{
	Byte data = memory[PC];
	PC++;
	cycles--;
	return data;
}

Word CPU::FetchWord(u32 &cycles, RAM &memory)
{
	Word Data = memory[PC];
	PC++;

	Data |= (memory[PC] << 8);
	PC++;

	cycles -= 2;

	return Data;
}

Byte CPU::ReadByte(u32 &cycles, Byte Address, RAM &memory)
{
	Byte data = memory[Address];
	cycles--;
	return data;
}

s32 CPU::Execute(u32 cycles, RAM &memory)
{
	s32 TotalCycles = cycles;
	while (cycles > 0)
	{
		Byte instruction = FetchByte(cycles, memory);
		switch (instruction)
		{

		case INS_LDA_IM:
		{
			Byte Value = FetchByte(cycles, memory);
			A = Value;
			LDASetStatus();
		}
		break;

		case INS_LDA_ZP:
		{
			Byte ZeroPageAddress = FetchByte(cycles, memory);
			A = ReadByte(cycles, ZeroPageAddress, memory);
			LDASetStatus();
		}
		break;

		case INS_LDA_ZPX:
		{
			Byte ZeroPageAddress = FetchByte(cycles, memory);
			ZeroPageAddress += X;
			cycles--;
			A = ReadByte(cycles, ZeroPageAddress, memory);
			LDASetStatus();
		}
		break;

		case INS_JSR:
		{
			Word SubroutineAddress = FetchWord(cycles, memory);
			memory.WriteWord(PC - 1, SP, cycles);
			PC = SubroutineAddress;
			cycles--;
		}
		break;

		default:
		{
			printf("Instruction Not Handeled %d \n", instruction);
		}
		break;
		}
	}
	return TotalCycles;
}
