#include <stdio.h>

int myAtoi(char *str)
{
  long num = 0;
  int sym = 1;
  int started = 0;
  long ret = 0;
  while (*str != 0)
  {
    if (started == 0)
    {
      if (*str == ' ') {}
      else if (*str == '+')
      {
        started = 1;
      }
      else if (*str == '-')
      {
        started = 1;
        sym *= -1;
      }
      else if ('0' <= *str && *str <= '9')
      {
        num *= 10;
        num += (*str - '0');
        started = 1;
      }
      else
        return 0;
    }
    else
    {
      if ('0' <= *str && *str <= '9')
      {
        num *= 10;
        num += (*str - '0');
      }
      else
      {
        break;
      }
    }
    ret = num * sym;
    if (2147483647 < ret) return 2147483647;
    else if (ret < -2147483648) return 2147483648;
    str++;
  }
  return ret;
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
  test("-003");
  test("003 ddds dd");
  test("-91283472332");
  test("91283472332");
  test("+2332");
  test("200000000000000000000000000000000000000000000");
  test("0-332");
  return 0;
}
