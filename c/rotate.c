#include <stdio.h>

// location(i) = (location(0) + i) % nums
// location(0) = k
void rotate1(int* nums, int numsSize, int k)
{
  int location = 0, current = 0, num = 0;
  while ((location = (k + current) % numsSize) != 0)
  {
    num = nums[location];
    nums[location] = nums[0];
    nums[0] = num;
    current = location;
  }
  if ((numsSize % k) / 2 == 0)
  {
    location = 0, current = 1, num = 0;
    while ((location = (k + current) % numsSize) != 1)
    {
      num = nums[location];
      nums[location] = nums[0];
      nums[0] = num;
      current = location;
    }
  }
}


int main()
{
  int nums[] = {1,2,3,4,5,6,7,8};
  rotate1(nums, 8, 4);
  for (int i = 0; i < 8; i++)
    printf("%d ", nums[i]);
  return 0;
}
