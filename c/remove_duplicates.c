#include <stdio.h>

// 双指针
int removeDuplicates(int* nums, int numsSize)
{
  if (numsSize == 0)
    return 0;
  unsigned int index = 0;
  for (unsigned int i = 1; i < numsSize; i++)
  {
    if (nums[index] != nums[i])
    {
      ++index;
      nums[index] = nums[i];
    }
  }
  return index + 1;
}

int main()
{
  int nums[10] = {0,0,1,1,1,2,2,3,3,4};
  int len = removeDuplicates(nums, 10);
  for (int i = 0; i < len; i++)
    printf("%d ", nums[i]);
  return 0;
}
