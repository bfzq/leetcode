#include <stdio.h>
#include <stdlib.h>
// timeout
int largestRectangleArea(int* heights, int heightsSize)
{
  int max = 0;
  for (int i = 0; i < heightsSize; i++)
  {
    int c = 1;
    int j = i - 1;
    while (j >= 0)
    {
      if (heights[j--] >= heights[i])
      {
        c++;
      }
      else
      {
        break;
      }
    }
    int z = i + 1;
    while (z < heightsSize)
    {
      if (heights[z++] >= heights[i])
      {
        c++;
      }
      else
      {
        break;
      }
    }
    int tmp = heights[i] * c;
    if (tmp > max) max = tmp;
  }
  return max;
}

// 单调栈
int largestRectangleArea2(int *heights, int heightsSize)
{
  int area = 0, idx = 0;
  int *stack = (int*)malloc(heightsSize + 2);
  
  stack[0] = 0;
  stack[heightsSize + 1] = 0;
  
  for (int i = 1; i < heightsSize; i++)
  {
    while (idx >= 1 && stack[idx] < heights[i])
    {
      
    }
    stack[++idx] = heights[i];
  }
  return area;
}

void test(int *h, int hs)
{
  printf("%d\n", largestRectangleArea(h, hs));
}
    

int main()
{
  int t1[] = {2,1,5,6,2,3};
  test(t1, sizeof(t1) / sizeof(int));
  int t2[] = {0};
  test(t2, sizeof(t2) / sizeof(int));
  int t3[] = {2,0,2};
  test(t3, sizeof(t3) / sizeof(int));
  int t4[] = {2,1,2};
  test(t4, sizeof(t4) / sizeof(int));
  return 0;
}
