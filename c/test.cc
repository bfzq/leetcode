#include <gtest/gtest.h>
#include "findmediansortedarrays.h"
#include "ismatch.h"



// g++ -std=c++11 -g test.cc -o test -I/usr/local/include -L/usr/local/lib -lgtest

int max(int a, int b)
{
  return a > b ? a : b;
}

TEST(test, max)
{
  EXPECT_EQ(2, max(2,-1));
  EXPECT_EQ(3, max(2,3));
}

TEST(leetcode, findMedianSortedArrays)
{
  int nums1[] = {};
  int nums2[] = {2};
  EXPECT_EQ(2.0,
            findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int),
                                   nums2, sizeof(nums2) / sizeof(int)));
  int nums3[] = {3};
  int nums4[] = {};
  EXPECT_EQ(3.0,
            findMedianSortedArrays(nums3, sizeof(nums3) / sizeof(int),
                                   nums4, sizeof(nums4) / sizeof(int)));

  int nums5[] = {};
  int nums6[] = {};
  EXPECT_EQ(0.0,
            findMedianSortedArrays(nums5, sizeof(nums5) / sizeof(int),
                                   nums6, sizeof(nums6) / sizeof(int)));

  int nums7[] = {1, 3};
  int nums8[] = {2};
  EXPECT_EQ(2.0,
            findMedianSortedArrays(nums7, sizeof(nums7) / sizeof(int),
                                   nums8, sizeof(nums8) / sizeof(int)));

  int nums9[] = {1, 3, 5, 6, 8};
  int nums10[] = {6, 9, 10};
  EXPECT_EQ(6.0,
            findMedianSortedArrays(nums9, sizeof(nums9) / sizeof(int),
                                   nums10, sizeof(nums10) / sizeof(int)));

  int nums11[] = {1, 3, 9, 10};
  int nums12[] = {12, 14, 19};
  EXPECT_EQ(10.0,
            findMedianSortedArrays(nums11, sizeof(nums11) / sizeof(int),
                                   nums12, sizeof(nums12) / sizeof(int)));

  int nums13[] = {1, 3, 6 , 10};
  int nums14[] = {};
  EXPECT_EQ(4.5,
            findMedianSortedArrays(nums13, sizeof(nums13) / sizeof(int),
                                   nums14, sizeof(nums14) / sizeof(int)));

  int nums15[] = {2};
  int nums16[] = {1};
  EXPECT_EQ(1.5,
            findMedianSortedArrays(nums15, sizeof(nums15) / sizeof(int),
                                   nums16, sizeof(nums16) / sizeof(int)));

  int nums17[] = {2, 2, 2};
  int nums18[] = {2, 2, 2, 2};
  EXPECT_EQ(2,
            findMedianSortedArrays(nums17, sizeof(nums17) / sizeof(int),
                                   nums18, sizeof(nums18) / sizeof(int)));

  int nums19[] = {2, 2, 2, 2, 2};
  int nums20[] = {2, 2, 2, 2};
  EXPECT_EQ(2,
            findMedianSortedArrays(nums19, sizeof(nums19) / sizeof(int),
                                   nums20, sizeof(nums20) / sizeof(int)));

  int nums21[] = {2, 3};
  int nums22[] = {1};
  EXPECT_EQ(2,
            findMedianSortedArrays(nums21, sizeof(nums21) / sizeof(int),
                                   nums22, sizeof(nums22) / sizeof(int)));
}

TEST(leetcode, isMatch)
{
  EXPECT_EQ(false, "aa", "a");
  EXPECT_EQ(true, "aa", "a*");
  EXPECT_EQ(true, "ab", ".*");
  EXPECT_EQ(true, "aab", "c*a*b");
  EXPECT_EQ(false, "mississippi", "mis*is*p*");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
