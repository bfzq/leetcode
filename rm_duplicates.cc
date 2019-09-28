#include <stdio.h>

#include <vector>

using namespace std;
int removeDuplicates1(vector<int> &nums)
{
  vector<int>::iterator i = nums.begin();
  int fst = 1, tmp = 0, count = 0;
  while (i != nums.end())
  {
    if (fst == 1)
    {
      fst = 0;
    }
    else
    {
      if (tmp == *i)
      {
        i = nums.erase(i);
        continue;
      }
    }
    tmp = *i;
    count++;
    i++;
  }
  return count;
}


int main()
{
  // int tmp_nums[10] = {0,0,1,1,1,2,2,3,3,4};
  vector<int> nums{0,0,1,1,1,2,2,3,3,4};
  int len = removeDuplicates(nums);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", nums[i]);
  }
  return 0;
}
