#include <stdio.h>
#include <stdbool.h>

bool isMatch(char *s, char *p)
{
  
  return false;
}

void test(char *s, char *p)
{
  printf("s:%s, p:%s ",s, p);
  if (isMatch(s, p) == true)
  {
    printf("true\n");
  }
  else
  {
    printf("false\n");
  }
  
}

int main()
{
  test("aa", "a");
  test("aa", "a*");
  test("ab", ".*");
  test("aab", "c*a*b");
  test("mississippi", "mis*is*p*.");
  return 0;
}
