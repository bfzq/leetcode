#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize)
{
  return 0;
}

void test(int *h, int hs)
{
  printf("%d\n", largestRectangleArea(h, hs));
}
    

int main()
{
  int t1[] = {2,1,5,6,2,3};
  test(t1, sizeof(t1) / sizeof(int));
  return 0;
}
