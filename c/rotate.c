#include <stdio.h>

void rotate1(int* nums, int numsSize, int k)
{
  printf("%d %d\n", numsSize, k);
  k = k % numsSize;
  int location = 0, current = 0, num = 0, x = 1, y;
  for (int i = 0; i < x; i++)
  {
    location = current = i;
    while ((location = (k + current) % numsSize) != i)
    {
      num = nums[location];
      nums[location] = nums[i];
      nums[i] = num;
      current = location;
      for (int i = 0; i < numsSize; i++)
        printf("%d,", nums[i]);
      printf("\n");
    }
    printf("---\n");
  }
}

void rotate3(int *nums, int numsSize, int k)
{
  int location = 0, current = 0, num = 0, count = 0;
  for (int i = 0; i < k; i++)
  {
    current = i;
    while ((location = (k + current) % numsSize) != i)
    {
      num = nums[location];
      nums[location] = nums[i];
      nums[i] = num;
      current = location;
      for (int i = 0; i < numsSize; i++)
        printf("%d,", nums[i]);
      printf("\n");
      count++;
    }
    printf("\n");
    if (count == (k % numsSize) - 1)
      break;
  }
}

void rotate2(int *nums, int numsSize, int k)
{
  if (numsSize < 2)
    return;
  for (int j = 0; j < k; j++)
  {
    for (int i = 0; i < numsSize; i++)
    {
      int num = nums[i + 1];
      nums[i + 1] = nums[i];
      
    }
  }
}


int main()
{
  int nums[] = {1,2,3,4,5,6,7};
  rotate3(nums, 7, 3);
  for (int i = 0; i < 7; i++)
    printf("%d ", nums[i]);
  printf("\n---\n");
  int nums2[] = {1,2,3,4,5,6};
  rotate3(nums2, 6, 4);
  for (int i = 0; i < 6; i++)
    printf("%d ", nums2[i]);
  return 0;
}
