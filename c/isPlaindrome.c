#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
  return false;
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
