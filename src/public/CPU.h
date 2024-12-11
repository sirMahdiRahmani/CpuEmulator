#pragma once
#include "RAM.h"

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;
using s32 = signed int;


struct CPU
{
    Word PC; // Program Counter
    Word SP; // Stack Pointer

    Byte A, X, Y; // Registers

    Byte C : 1; // Carry Status Flag
    Byte Z : 1; // Zero Status Flag
    Byte I : 1; // Interrupt Disabled Status Flag
    Byte D : 1; // Decimal Mode Status Flag
    Byte B : 1; // Break Coommand Status Flag
    Byte V : 1; // Overflow Status Flag
    Byte N : 1; // Negative Status Flag

    static constexpr Byte 
        INS_LDA_IM = 0xA9,
        INS_LDA_ZP = 0xA5,
        INS_LDA_ZPX = 0xB5,
        INS_JSR = 0x20;

    void Reset(RAM& memory);

    void LDASetStatus();

    // Read 1 Byte
    Byte FetchByte(u32& cycles, RAM& memory);
    Word FetchWord(u32& cycles, RAM& memory);
    Byte ReadByte(u32& cycles, Byte Address, RAM& memory);

    s32 Execute(u32 cycles, RAM& memory);
};
