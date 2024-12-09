#include "RAM.h"

void RAM::Initialize()
{
    for (u32 i = 0; i < MAX_MEM; i++)
    {
        Data[i] = 0;
    }
}

Byte RAM::operator[](u32 address)
{
    //! Assert here address < MAX_MEM
    return Data[address];
}
