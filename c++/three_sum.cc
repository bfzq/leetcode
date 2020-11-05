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
      while (i < nums.size() && i > 0 && nums[i] == nums[i - 1])
        i++;

      for (int j = i + 1; j < nums.size(); j++)
      {
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
};

int main()
{
  Solution sum;
  vector<int> in = {0,0,0,0};
  sum.threeSum(in);
  return 0;
}

#endif // _THREE_SUM_
