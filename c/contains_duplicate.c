#include <stdio.h>
#include <stdbool.h>

/* timeout for */
bool contains_duplicate(int *nums, int numsSize)
{
  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] == nums[j])
        return true;
    }
  }
  return false;
}


int main()
{
  int nums1[] = {1,2,3,1};
  printf("%d", contains_duplicate(nums1, 4));
  return 0;
}
