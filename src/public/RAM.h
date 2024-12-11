#pragma once

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct RAM
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialize();

    Byte operator[](u32 address) const;
    Byte& operator[](u32 address);
    void WriteWord(Word value, u32 address, u32& cycle);
};
