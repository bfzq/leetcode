/*
Given an array of integers, return indices of the two numbers such that they add
 up to a specific target.

You may assume that each input would have exactly one solution, and you may not 
use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#ifndef _TWO_SUM_
#define _TWO_SUM_

#include <vector>
#include "base.h"

typedef std::vector<int> nums_vector;

class Twosum : public Base
{
private:
  nums_vector twoSum(nums_vector& nums, int target);
private:
  bool verify_result(nums_vector* idx, nums_vector* nums, int target);
public:
  void run_test(char *argv[]);
};

#endif // _TWO_SUM_
