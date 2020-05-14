#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  double mid = 0;
  double midx = (nums1Size + nums2Size) / 2;
  int idx1 = 0, idx2 = 0;
  while (idx1 < nums1Size || idx2 < nums2Size)
  {
    if (nums2[idx2] < nums1[idx1])
    {
      int t = (nums2Size + idx2) / 2;
      while (t + idx1 + 1 > midx)
      {
        
      }
    }
    else if (nums2[idx2] > nums1[idx1])
    {
      idx1 = (nums1Size/2 + idx1) / 2;
    }
  }
  return mid;
}

double findMedianSortedArrays2(int* nums1, int nums1Size,
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

double findMedianSortedArrays3(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  double count = nums1Size + nums2Size;
  double mid = count / 2;
  unsigned l = 0, r = 0;
  while (r - l <= 1 && (l + r) / 2 == mid)
  {
    
  }
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
