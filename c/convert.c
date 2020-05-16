#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* convert(char *s, int numRows)
{
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
  test("LEETCODEISHIRING", 3);
  test("LEETCODEISHIRING", 4);
  return 0;
}
