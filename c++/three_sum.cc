#ifndef _THREE_SUM_
#define _THREE_SUM_
#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0) break;
      while (i < nums.size() && i > 0 && nums[i] == nums[i - 1])
        i++;

      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] + nums[j] > 0) break;
        while (j < nums.size() && j > i + 1 && nums[j] == nums[j - 1])
          j++;

        for (int z = j + 1; z < nums.size(); z++)
        {
          while (z < nums.size() && z > j + 1 && nums[z] == nums[z - 1])
            z++;

          if (z >= nums.size() || nums[i] + nums[j] + nums[z] > 0)
            break;
          else if (nums[i] + nums[j] + nums[z] == 0)
          {
            vector<int> r;
            r.push_back(nums[i]);
            r.push_back(nums[j]);
            r.push_back(nums[z]);
            ret.push_back(r);
          }
        }
      }
    }
    return ret;
  }

  vector<vector<int>> threeSum2(vector<int>& nums) {
    vector<vector<int>> ret;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0) break;
      while (i < nums.size() && i > 0 && nums[i] == nums[i - 1])
        i++;
      for (int j = i + 1; j < nums.size(); j++)
      {
        if (nums[i] + nums[j] > 0) break;
        while (j < nums.size() && j > i + 1 && nums[j] == nums[j - 1])
          j++;
        if (j >= nums.size()) break;

        int a = j + 1;
        int b = nums.size() - 1;
        int m = 0;
        int value = 0 - (nums[i] + nums[j]);
        while (a <= b)
        {
          // m = (a  + b + 1) / 2;
          m = a + (b - a) / 2;
          if (nums[m] < value)
          {
            a = m + 1;
          }
          else if (nums[m] > value)
          {
            b = m - 1;
          }
          else
          {
            vector<int> r;
            r.push_back(nums[i]);
            r.push_back(nums[j]);
            r.push_back(nums[m]);
            ret.push_back(r);
            break;
          }
        }
      }
    }
    return ret;
  }
};

int main()
{
  Solution sum;
  // vector<int> in = {-1,0,-1,2,1,-4};
  vector<int> in = {0,0,0,0};
  sum.threeSum2(in);
  return 0;
}

#endif // _THREE_SUM_
