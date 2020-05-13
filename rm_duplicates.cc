#include <stdio.h>

#include <vector>

using namespace std;
int rm_duplicates1(vector<int> &nums)
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

/*
  双指针法
 */
int rm_duplicates2(vector<int> &nums)
{
  int num = nums.size();
  int i, j = 0;
  for (i = 0; i < num; i++)
  {
    if ((nums[j] != nums[i]) && (j != (i + 1)))
    {    
      nums[++j] = nums[i];
    }
  }
  return i == 0 ? j : j + 1;
}

int main()
{
  // int tmp_nums[10] = {0,0,1,1,1,2,2,3,3,4};
  vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5, 5};
  // vector<int> nums{1, 1};
  int len = rm_duplicates2(nums);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", nums[i]);
  }
  return 0;
}
