#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char * s)
{
  int max = 0;
  bool chars[93] = {false};
  int i = 0, j = 0;
  int len = strlen(s);
  while (j < len)
  {
    int idx = s[j] - 32;
    if (chars[idx] == true)
    {
      if (max < j - i)
        max = j - i;
      int idx2 = 0;
      do
      {
        idx2 = s[i++] - 32;
        chars[idx2] = false;
      }
      while (idx != idx2);
    }
    else
    {
      chars[idx] = true;
      j++;
    }
  }
  if (max < j - i)
    max = j - i;
  return max;
}

int lengthOfLongestSubstring2(char * s)
{
  int i = 0, max = 0;
  do
  {
    for (int j = i; s[j] != 0; j++)
    {
      for (int z = i; z < j; z++)
      {
        
      }
    }
  }
  while (s[i] != 0);
}

int main()
{
  printf("%d", lengthOfLongestSubstring(" "));
}
