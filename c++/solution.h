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

 private:
  int min(int a, int b)
  {
    return a < b ? a : b;
  }

  int max(int a, int b)
  {
    return a < b ? b : a;
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

};

#endif // _LEETCODE_SOLUTION_
