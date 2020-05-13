#include <stdio.h>

bool verifyPostorder(int *postorder, int postorderSize)
{
  if (postorderSize <= 2)
    return true;
  int t[3];
  int i = 1;
  t[0] = postorder[0];
  int size = 0;
  while ((size = postorderSize - i) > 2)
  {
    t[1] = postorder[i + 0];
    t[2] = postorder[i + 1];
    if (t[0] < t[1] && t[2] < t[1] && t[0] < t[2])
    {
      t[0] = t[1];
    }
    else if ((t[0] < t[1] && t[1] < t[2]))
    {
      t[0] = t[2];
    }
    else if (t[0] > t[1] && t[1] > t[2])
    {}
    else
    {
      return false;
    }
    i += 2;
  }
  return true;
}

int main()
{
  int p1[] = {1};
  printf("%u\n", verifyPostorder(p1, 1));
  int p2[] = {1, 2};
  printf("%u\n", verifyPostorder(p2, 2));
  int p3[] = {1, 3, 2};
  printf("%u\n", verifyPostorder(p3, 3));
  int p4[] = {4, 6, 7, 5};
  printf("%u\n", verifyPostorder(p4, 4));
  int p5[] = {5, 4, 3, 2, 1};
  printf("%u\n", verifyPostorder(p5, 5));
  int p6[] = {7,4,6,5};
  printf("%u\n", verifyPostorder(p6, 4));
  int p7[] = {1,2,5,10,6,9,4,3};
  printf("0 %u\n", verifyPostorder(p7, 8));
  /* int p8[] = {1}; */
  /* printf("%u", verifyPostorder(p8, 8)); */
  /* int p9[] = {1}; */
  /* printf("%u", verifyPostorder(p9, 9)); */
  return 0;
}
