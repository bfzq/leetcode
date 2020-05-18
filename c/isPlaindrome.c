#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
  if (x < 0) return false;
  int x2 = x;
  long x3 = 0;
  do
  {
    x3 *= 10;
    x3 += x2 % 10;
    if ((int)x3 != x3) return false;
    x2 /= 10;
  } while (x2 != 0);
  return x == x3 ? true : false;
}


void test(int x)
{
  printf("input %d ", x);
  if (isPalindrome(x))
  {
    printf("is palindrome\n");
  }
  else
  {
    printf("is not plaindrome\n");
  }
}

int main()
{
  test(121);
  test(-121);
  test(10);
  test(0);
  test(-1);
  test(123);
  test(0x7FFFFFFF);
  return 0;
}
