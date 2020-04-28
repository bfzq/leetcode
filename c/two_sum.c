#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum1(int* nums, int numsSize, int target, int* returnSize)
{
  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        int *result = (int*)malloc(sizeof(int) * 2);
        result[0] = i;
        result[1] = j;
        *returnSize = 2;
        return result;
      }
    }
  }
  *returnSize = 0;
  return NULL;
}

int main()
{
  int nums[] = {2, 7, 11, 15};
  int result_size = 0;
  int *result = twoSum1(nums, 4, 9, &result_size);
  for (int i = 0; i < result_size; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
