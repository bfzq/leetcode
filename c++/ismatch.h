/*
  '.' 匹配任意单个字符
  '*' 匹配零个或多个前面的那一个元素
*/
#include <string>

class Solution
{
 public:
  bool isMatch(std::string s, std::string p)
  {
    if (s.empty() != true && p.empty() == true)
      return false;

    char pre_char = 0;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (p[j] == '.')
      {
        pre_char = p[j];
      }
      else if (p[j] == '*')
      {
        if (pre_char == s[i] || pre_char == '.')
          continue;
        else
        {
          i--;
        }
      }
      else
      {
        if (s[i] == p[j])
          pre_char = s[i];
        else if (p[j + 1] == '*')
        {
          pre_char = p[j];
          i--;
        }
        else
          return false;
      }
      j++;
    }
    while (j < p.size())
    {
      if (p[j] == '.') return false;
      if ('a' <= p[j] && p[j] <= 'z') return false;
      j++;
    }
    return true;
  }
};
