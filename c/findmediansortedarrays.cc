#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  int left_total_element_num = (nums1Size + nums2Size + 1) / 2;
  int left_element_num1 = 0, left_element_num2 = 0;
  while (left_element_num1 + left_element_num2 != left_total_element_num)
  {
    
  }
  if ()
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
