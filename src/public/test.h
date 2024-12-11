#pragma once
#include <gtest/gtest.h>
#include "CPU.h"
#include "RAM.h"

class CpuEmulatorTest : public testing::Test
{
public:

    RAM memory;
    CPU processor;

    virtual void SetUp()
    {
        processor.Reset(memory);
    }

    virtual void TearDown()
    {

    }
};
