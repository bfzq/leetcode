#include <gtest/gtest.h>
#include "findmediansortedarrays.h"

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
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
