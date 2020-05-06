#include <stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  int count = nums1Size + nums2Size;
  int t = count % 2;
  int lmid = 0, rmid = 0;
  rmid = (nums1Size + nums2Size) / 2;
  if (t == 0)
  {
    lmid = rmid - 1;
  }
  else
  {
    lmid = rmid;
  }
  int idx = 0, lv = 0, rv = 0;
  while (nums1 == NULL && nums2 == NULL)
  {
    
  }
  return ((double)(lmid + rmid)) / 2;
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
