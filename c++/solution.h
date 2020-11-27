#ifndef _LEETCODE_SOLUTION_
#define _LEETCODE_SOLUTION_

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
 public:
  int maxArea(vector<int>& height)
  {
    // return bruteForce(height);
    return twoPointers(height);
  }

  int romanToInt(string s)
  {
    return romanToInt1(s);
  }

  string intToRoman(int num)
  {
    return intToRoman1(num);
  }
  /*  14. Longest Common Prefix */
  string longestCommonPrefix(vector<string>& strs)
  {
    return longestCommonPrefix1(strs);
  }

  /**
     Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

     Notice that the solution set must not contain duplicate triplets.

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/3sum
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    return threeSum0(nums);
  }
 private:
  vector<vector<int>> threeSum0(vector<int> &nums)
  {
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
  /*  passed */
  int romanToInt1(string s)
  {
    if (s.empty()) return 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (i + 1 < s.size() && getInt(s[i]) < getInt(s[i + 1]))
      {
        tmp += (getInt(s[i + 1]) - getInt(s[i]));
        i++;
      }
      else
      {
        tmp += getInt(s[i]);
      }
    }
    return tmp;
  }

  /* passed */
  string intToRoman1(int num)
  {
    string ret;
    int n = 0;
    int t = 1;
    while (num != 0)
    {
      n = num % 10;
      if (n == 4 || n == 9)
      {
        ret.insert(0, getRoman((n + 1) * t));
        ret.insert(0, getRoman(t));
      }
      else if (n < 4)
      {
        for (int i = 0; i < n; i++)
        {
          ret.insert(0, getRoman(t));
        }
      }
      else
      {
        // n >= 5
        for (int i = 0; i < n - 5; i++)
        {
          ret.insert(0, getRoman(t));
        }
        ret.insert(0, getRoman(5 * t));
      }
      t *= 10;
      num /= 10;
    }
    return ret;
  }
  /* for longestCommonPrefix
     brute force
     passed
  */
  string longestCommonPrefix1(vector<string> &strs)
  {
    if (strs.empty() == true)
      return "";
    if (strs[0].empty())
      return "";
    string ret;
    for (int i = 0; i < strs[0].length(); i++)
    {
      ret.push_back(strs[0][i]);
      for (int j = 1; j < strs.size(); j++)
      {
        if (!(i < strs[j].length() &&
              strs[j][i] == ret[i]))
        {
          ret.erase(ret.end() - 1);
          goto ret_label;
        }
      }
    }
  ret_label:
    return ret;
  }
  int min(int a, int b)
  {
    return a < b ? a : b;
  }

  int max(int a, int b)
  {
    return a < b ? b : a;
  }

  /*  for romanToInt */
  int getInt(char roman)
  {
    switch (roman)
    {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    default:
      return 1000;
    }
  }

  string getRoman(int num)
  {
    switch (num)
    {
    case 1:
      return "I";
    case 5:
      return "V";
    case 10:
      return "X";
    case 50:
      return "L";
    case 100:
      return "C";
    case 500:
      return "D";
    default:
      return "M";
    }
  }

  /* for maxArea*/
  // brute force is time out
  int bruteForce(vector<int> &height)
  {
    int max_area = 0;
    for (int i = 0; i < height.size(); i++)
    {
      for (int j = i + 1; j < height.size(); j++)
      {
        int hi = height[i];
        int hj = height[j];
        int wide = j - i;
        int tmp = (hi < hj) ? hi * wide : hj * wide;
        max_area = max(tmp, max_area);
      }
    }
    return max_area;
  }

  // two pointers, passed
  int twoPointers(vector<int> &height)
  {
    unsigned left = 0;
    unsigned right = height.size() - 1;
    int max_area = 0;
    while (left != right)
    {
      unsigned left_height = height[left];
      unsigned right_height = height[right];
      int tmp = min(left_height, right_height) * (right - left);
      max_area = max(max_area, tmp);
      left_height < right_height ? left++ : right--;
    }
    return max_area;
  }
 public:
  int threeSumClosest1(vector<int>& nums, int target) {
    return 1;
  }

  /**
     Write a method that finds the maximum of two numbers. You should not use if-else or any other comparison operator.

     Example:

     Input:  a = 1, b = 2
     Output:  2

     来源：力扣（LeetCode）
     链接：https://leetcode-cn.com/problems/maximum-lcci
     著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */
  int maximum1(int a, int b)
  {
    int64_t a1 = a;
    int64_t b1 = b;
    int64_t c = a1 - b1;
    int ret = 0;
    (c >> 63) ? ret = b : ret =  a;
    return ret;
  }
};

#endif // _LEETCODE_SOLUTION_
