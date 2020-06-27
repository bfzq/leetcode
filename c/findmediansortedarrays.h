#ifndef _FINDMEDIANSORTEDARRAYS_H_
#define _FINDMEDIANSORTEDARRAYS_H_

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size)
{
  bool is_even = false;
  if ((nums1Size + nums2Size) % 2 == 0) is_even = true;

  int left_median_element_num = (nums1Size + nums2Size + 1) / 2;
  /* if (nums1Size == 0 && nums2Size == 0) */
  /* { */
  /*   return 0; */
  /* } */
  /* else if (nums1Size == 0) */
  /* { */
  /*   if () */
  /* } */
  /* else if (nums2Size == 0) */
  /* { */
  /*   return 2; */
  /* } */
  int left_element_num1 = 0, left_element_num2 = 0;
  int mid = 0;
  while (left_element_num1 + left_element_num2 != left_median_element_num)
  {
    if (nums1[left_element_num1] <= nums2[left_element_num2])
    {
      mid = (left_element_num1 + nums1Size) / 2;
      while (mid + left_element_num2 >
             left_median_element_num ||
             nums1[mid] > nums2[left_element_num2])
      {
        mid = (left_element_num1 + mid) / 2;
      }
      left_element_num1 = mid + 1;
    }
    else
    {
      mid = (left_element_num2 + nums2Size) / 2;
      while (mid + left_element_num1 >
             left_median_element_num ||
             nums2[mid] > nums1[left_element_num1])
      {
        mid = (left_element_num2 + mid) / 2;
      }
      left_element_num2 = mid + 1;
    }
  }
  if (left_element_num1 == 0 && left_element_num2 == 0) return 0;
  double left_value = 0;
  if (left_element_num1 != 0 && left_element_num2 == 0)
  {
    left_value = nums1[left_element_num1 - 1];
  }
  else if (left_element_num1 == 0 && left_element_num2 != 0)
  {
    left_value = nums2[left_element_num2 - 1];
  }
  else
  {
    left_value = nums1[left_element_num1 - 1] > nums2[left_element_num2 - 1] ?
      nums1[left_element_num1 - 1] : nums2[left_element_num2 - 1];
  }

  if (is_even == true)
  {
    double right_value = 0;
    if (left_element_num1 == nums1Size)
    {
      right_value = nums2[left_element_num2];
    }
    else if (left_element_num2 == nums2Size)
    {
      right_value = nums1[left_element_num1];
    }
    else
    {
      right_value = nums1[left_element_num1] < nums2[left_element_num2] ?
        nums1[left_element_num1] : nums2[left_element_num2];
    }
    return (left_value + right_value) / 2;
  }
  else
  {
    return left_value;
  }
}

#endif // _FINDMEDIANSORTEDARRAYS_H_
