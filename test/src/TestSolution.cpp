#include "TestSolution.h"
#include "solution.h"
#include <thread>

void CTestSolution::SetUp()
{
}

void CTestSolution::TearDown()
{
}

// Test solution result is 10
TEST(CTestSolution, Test1)
{
    std::vector<std::vector<int>> values = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
    Solution solution;
    auto result = solution.getNumPaths(values);
    ASSERT_TRUE(result == 10);  
}

// Test solution result is 2
TEST(CTestSolution, Test2)
{
    std::vector<std::vector<int>> values = {{1,1,1}, {1,0,1}, {1,1,1}};
    Solution solution;
    auto result = solution.getNumPaths(values);
    ASSERT_TRUE(result == 2);  
}

// Test solution result is 0
TEST(CTestSolution, Test3)
{
    std::vector<std::vector<int>> values = {{1,1,1}, {1,1,1}, {1,1,0}};
    Solution solution;
    auto result = solution.getNumPaths(values);
    ASSERT_TRUE(result == 0);  
}

// Test solution result is 0
TEST(CTestSolution, Test4)
{
    std::vector<std::vector<int>> values = {{1}};
    Solution solution;
    auto result = solution.getNumPaths(values);
    ASSERT_TRUE(result == 0);  
}