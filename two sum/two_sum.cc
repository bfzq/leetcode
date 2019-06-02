#include "two_sum.h"
#include <iostream>
#include <unordered_map>
#include "global.h"
#include <string.h>

using namespace std;

// typedef unordered_map<int, int> val_idx_mapping;

vector<int>
Twosum::twoSum(nums_vector& nums, int target)
{
  unordered_map<int, int> val_idx;
   for (uint i = 0; i < nums.size(); i++)
   {
     int val = nums[i];
     unordered_map<int, int>::iterator iter = val_idx.find(val);
     if (iter != val_idx.end())
     {
       return {iter->second, (int)i};
     }
     val_idx[target - val] = i;
   }
   return {};
}

/*
  ./leetcode two_sum [2,7,11,15] 9
*/
nums_vector get_nums(char *nums_c)
{
  nums_vector nums;
  nums_c++;
  nums_c[strlen(nums_c)] = '\0';
  char *n = strtok(nums_c, ",");
  while (n != NULL)
  {
    nums.push_back(atoi(n));
    n = strtok(NULL, ", ");
  }
  return nums;
}

void
Twosum::run_test(char *argv[])
{
  nums_vector nums = get_nums(argv[0]);
  if (nums.size() < 2)
  {
    cout << "input error." << endl;
    return;
  }
  int target = atoi(argv[1]);
  nums_vector idx = twoSum(nums, target);
  if (verify_result(&idx, &nums, target))
  {
    cout << "test success!" << endl;
  }
  else
  {
    cout << "test faild!" << endl;
  }
  
}


bool
Twosum::verify_result(nums_vector *idx, nums_vector* nums, int target)
{
  if (idx->size() != 2 && idx == nullptr)
    return false;
  if (((*nums)[(*idx)[0]] + (*nums)[(*idx)[1]]) == target)
    return true;
  else
    return false;
}
