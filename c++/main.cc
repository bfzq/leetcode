#include <gtest/gtest.h>
#include "solution.h"
#include <iostream>

TEST(LEETCODE, maxArea)
{
  Solution s;
  vector<int> input = {1,8,6,2,5,4,8,3,7};
  EXPECT_EQ(49, s.maxArea(input));
}


TEST(LEETCODE, romanToInt)
{
  Solution s;
  string ss = "MCMXCIV";
  EXPECT_EQ(1994, s.romanToInt(ss));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
