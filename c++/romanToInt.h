#include <string>
using std::string;
class Solution {
 private:
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
 public:
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
};
