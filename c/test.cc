#include <gtest/gtest.h>

// g++ -std=c++11 -g test.cc -o test -I/usr/local/include -L/usr/local/lib -lgtest


int max(int a, int b)
{
  return a>b?a:b;
}

TEST(test, max)
{
  EXPECT_EQ(2, max(2,-1));
  EXPECT_EQ(3, max(2,3));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
