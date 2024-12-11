#include <iostream>
#include "test.h"
#include "CPU.h"
#include "RAM.h"

#define TEST 1

# if TEST == 1

TEST_F(CpuEmulatorTest, LDAImmediateCanLoadValueInARegister)
{
    //* given:
    memory[0xFFFC] = CPU::INS_LDA_IM;
    memory[0xFFFD] = 0x84;
    
    //? when:
    CPU processorCopy = processor;
    s32 numberOfCycles = processor.Execute(2, memory);

    //! then:
    EXPECT_EQ(processor.A, 0x84);
    EXPECT_EQ(numberOfCycles, 2);
    EXPECT_FALSE(processor.Z);
    EXPECT_TRUE(processor.N);
    EXPECT_EQ(processor.C, processorCopy.C);
    EXPECT_EQ(processor.I, processorCopy.I);
    EXPECT_EQ(processor.D, processorCopy.D);
    EXPECT_EQ(processor.B, processorCopy.B) ;
    EXPECT_EQ(processor.V, processorCopy.V) ;
}

TEST_F(CpuEmulatorTest, LDAZeroPageCanLoadValueInARegister)
{
    //* given:
    memory[0xFFFC] = CPU::INS_LDA_ZP;
    memory[0xFFFD] = 0x42;
    memory[0x0042] = 0x37;
    
    //? when:
    CPU processorCopy = processor;
    s32 numberOfCycles = processor.Execute(3, memory);

    //! then:
    EXPECT_EQ(processor.A, 0x37);
    EXPECT_EQ(numberOfCycles, 3);
    EXPECT_FALSE(processor.Z);
    EXPECT_FALSE(processor.N);
    EXPECT_EQ(processor.C, processorCopy.C);
    EXPECT_EQ(processor.I, processorCopy.I);
    EXPECT_EQ(processor.D, processorCopy.D);
    EXPECT_EQ(processor.B, processorCopy.B) ;
    EXPECT_EQ(processor.V, processorCopy.V) ;

}

TEST_F(CpuEmulatorTest, LDAZeroPageXCanLoadValueInARegister)
{
    processor.X = 5;
    //* given:
    memory[0xFFFC] = CPU::INS_LDA_ZPX;
    memory[0xFFFD] = 0x42;
    memory[0x0047] = 0x37;
    
    //? when:
    CPU processorCopy = processor;
    s32 numberOfCycles = processor.Execute(4, memory);

    //! then:
    EXPECT_EQ(processor.A, 0x37);
    EXPECT_EQ(numberOfCycles, 4);
    EXPECT_FALSE(processor.Z);
    EXPECT_FALSE(processor.N);
    EXPECT_EQ(processor.C, processorCopy.C);
    EXPECT_EQ(processor.I, processorCopy.I);
    EXPECT_EQ(processor.D, processorCopy.D);
    EXPECT_EQ(processor.B, processorCopy.B) ;
    EXPECT_EQ(processor.V, processorCopy.V) ;
}

TEST_F(CpuEmulatorTest, LDAZeroPageXCanLoadValueInARegisterWhenItWraps)
{
    processor.X = 0xFF;
    //* given:
    memory[0xFFFC] = CPU::INS_LDA_ZPX;
    memory[0xFFFD] = 0x80;
    memory[0x007F] = 0x37;
    
    //? when:
    CPU processorCopy = processor;
    s32 numberOfCycles = processor.Execute(4, memory);

    //! then:
    EXPECT_EQ(processor.A, 0x37);
    EXPECT_EQ(numberOfCycles, 4);
    EXPECT_FALSE(processor.Z);
    EXPECT_FALSE(processor.N);
    EXPECT_EQ(processor.C, processorCopy.C);
    EXPECT_EQ(processor.I, processorCopy.I);
    EXPECT_EQ(processor.D, processorCopy.D);
    EXPECT_EQ(processor.B, processorCopy.B) ;
    EXPECT_EQ(processor.V, processorCopy.V) ;
}

#else
int main()
{
    RAM memory;
    CPU cpu;
    cpu.Reset(memory);

    memory[0xFFFC] = CPU::INS_LDA_ZP;
    memory[0xFFFD] = 0x42;
    memory[0x0042] = 0x84;
        
    cpu.Execute(4, memory);

    std::cout << "Done!" << std::endl;
    return 0;
}
#endif