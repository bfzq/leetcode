

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

int main()
{
  return 0;
}
