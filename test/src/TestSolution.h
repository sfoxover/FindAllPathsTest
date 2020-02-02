#pragma once
#include <gtest/gtest.h>

class CTestSolution : public ::testing::Test 
{
protected:
    virtual void SetUp();
    virtual void TearDown();
};