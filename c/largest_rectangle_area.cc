#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  if (heightsSize == 0) return 0;
  int area = 0, top = 0;
  int *stack = (int*)malloc(heightsSize * sizeof(int));
  memset(stack, 0, heightsSize * sizeof(int));
  stack[top] = 0;
  for (int i = 1; i < heightsSize + 1; i++)
  {
    while (top >= 0 &&
           (i == heightsSize || heights[stack[top]] > heights[i]))
    {
      int height = heights[stack[top]];

      /* stack 左边空缺的值的都是大于当前的值 */
      int left = top-- == 0 ? -1 : stack[top];
      
      int right = i - 1;
      int tmp = height * (right - left);
      if (tmp > area) area = tmp;
    }
    stack[++top] = i;
  }
  free(stack);
  return area;
}

void test(int *h, int hs)
{
  printf("%d\n", largestRectangleArea2(h, hs));
}
    

int main()
{
  int t1[] = {2,1,5,6,2,3};
  test(t1, sizeof(t1) / sizeof(int));
  int t2[] = {0};
  test(t2, sizeof(t2) / sizeof(int));
  int t3[] = {2,1,2};
  test(t3, sizeof(t3) / sizeof(int));
  int t4[] = {2,3,1,1,1};
  test(t4, sizeof(t4) / sizeof(int));
  int t5[] = {};
  test(t5, sizeof(t5) / sizeof(int));
  int t6[] = {0,3,2,5};
  test(t6, sizeof(t6) / sizeof(int));
  return 0;
}
