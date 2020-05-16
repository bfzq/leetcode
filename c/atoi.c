#include <stdio.h>

int myAtoi(char *str)
{
  return 0;
}

void test(char * str)
{
  printf("%d\n", myAtoi(str));
}

int main()
{
  test("    -41");
  test("410");
  test("003");
  test("003 ddds dd");
  test("-91283472332");
  test("+2332");
  return 0;
}
