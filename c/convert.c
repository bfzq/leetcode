#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char *s, int numRows)
{
  if (numRows == 1) return s;
  int len = strlen(s);
  char *s_ = (char*)malloc(len + 1);
  char *s__ = s_;
  int step = (numRows - 1) * 2;
  for (int i = 0; i < numRows; i++)
  {
    int j = 0;
    while (1)
    {
      if (j == 0 || i == numRows - 1 || i == 0)
      {
        if (j + i >= len) break;
        *s_ = s[j + i];
        s_++;
      }
      else
      {
        if (j - i >= len) break;
        *s_ = s[j - i];
        s_++;
        if (j + i >= len) break;
        *s_ = s[j + i];
        s_++;
      }
      j += step;
    }
  }
  s__[len] = 0;
  strcpy(s, s__);
  free(s__);
  return s;
}

void test(char *s, int numRows)
{
  int len = strlen(s);
  char *s_ = (char*)malloc(len);
  strcpy(s_, s);
  char *s__ = convert(s_, numRows);
  printf("input: %s, output: %s\n", s, s__);
  free(s__);
}

int main()
{
  test("LEETCODEISHIRING", 1);
  test("LEETCODEISHIRING", 2);
  test("LEETCODEISHIRING", 3);
  test("LEETCODEISHIRING", 4);
  test("LEETCODEISHIRING", 16);
  return 0;
}
