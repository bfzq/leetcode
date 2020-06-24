#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  return 0;
}

void test1()
{
  int num1[] = {1, 3};
  int num2[] = {2};
  double mid = findMedianSortedArrays(num1, 2, num2, 1);
  printf("%f\n", mid);
}

int main()
{
  test1();
  return 0;
}
