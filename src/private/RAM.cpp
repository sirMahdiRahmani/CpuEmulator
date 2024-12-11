#include "RAM.h"

void RAM::Initialize()
{
    for (u32 i = 0; i < MAX_MEM; i++)
    {
        Data[i] = 0;
    }
}

Byte RAM::operator[](u32 address) const
{
    //! Assert here address < MAX_MEM
    return Data[address];
}

Byte& RAM::operator[](u32 address)
{
    //! Assert here address < MAX_MEM
    return Data[address];
}

void RAM::WriteWord(Word value, u32 address, u32& cycles)
{
    Data[address] = value & 0xFF;
    Data[address + 1] = (value >> 8);
    cycles -= 2;
}
