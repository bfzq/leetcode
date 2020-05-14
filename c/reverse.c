#include <stdio.h>

int reverse(int x)
{
  double num = 0;
  int c = 0;
  while (x != 0)
  {
    c = x % 10;
    num += c;
    x /= 10;
    if (x)
    {
      num *= 10;
      if (num > 2147483647 || num < -2147483648) return 0;
    }
  }
  return num;
}

int main()
{
  printf("%d", reverse(-2147483648));
  return 0;
}
