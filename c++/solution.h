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

  string intToRoman(int num)
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
  /*  14. Longest Common Prefix */
  string longestCommonPrefix(vector<string>& strs)
  {
    return longestCommonPrefix1(strs);
  }
 private:
  /* for longestCommonPrefix
     brute force
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


};

#endif // _LEETCODE_SOLUTION_
