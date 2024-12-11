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
    processor.Execute(2, memory);

    //! then:
    EXPECT_EQ(processor.A, 0x84);
}

TEST_F(CpuEmulatorTest, LDAZeroPageCanLoadValueInARegister)
{
    //* given:
    memory[0xFFFC] = CPU::INS_LDA_ZP;
    memory[0xFFFD] = 0x42;
    memory[0x0042] = 0x37;
    
    //? when:
    processor.Execute(3, memory);

    //! then:
    EXPECT_EQ(processor.A, 0x37);
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