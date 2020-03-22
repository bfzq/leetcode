#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/* timeout for */
bool contains_duplicate(int *nums, int numsSize)
{
  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] == nums[j])
        return true;
    }
  }
  return false;
}

// binary tree
struct node_struct
{
  int num;
  struct node_struct *left, *right;
};
typedef struct node_struct node_t;
bool contains_duplicate2(int *nums, int numsSize)
{
  node_t *head = NULL, *p = NULL;
  for (int i = 0; i < numsSize; i++)
  {
    if (head == NULL)
    {
      node_t node;
      node.num = nums[i];
      node.left = node.right = NULL;
      head = &node;
    }
    else
    {
      p = head;
      while (p != NULL)
      {
        if (p->num < nums[i])
        {
          if (p->right != NULL)
            p = p->right;
          else
          {
            node_t node;
            node.num = nums[i];
            node.left = node.right = NULL;
            p->right = &node;
            break;
          }
        }
        else if (p->num > nums[i])
        {
          if (p->left != NULL)
            p = p->left;
          else
          {
            node_t node;
            node.num = nums[i];
            node.left = node.right = NULL;
            p->left = &node;
            break;
          }
        }
        else
        {
          return true;
        }
      }
    }
  }
  return false;
}

// hash + linear probing
// timeout
bool contains_duplicate3(int *nums, int numsSize)
{
  int **tbl = (int**)malloc(numsSize * sizeof(int*));
  memset(tbl, 0, numsSize * sizeof(int*));
  int idx = 0;
  bool ret = false;
  for (int i = 0; i < numsSize; i++)
  {
    if (*(nums + i) < 0)
      idx = ((*(nums + i) * -1) + numsSize / 2) % numsSize;
    else
      idx = *(nums + i) % numsSize;
    if (tbl[idx] == NULL)
      tbl[idx] = &(nums[i]);
    else if (*(tbl[idx]) == nums[i])
    {
      ret = true;
    }
    else
    {
      for (int j = (idx + 1) % numsSize; j != idx; j = (j + 1) % numsSize)
      {
        if (tbl[j] == NULL)
        {
          tbl[j] = &(nums[i]);
          break;
        }
        else if (*(tbl[j]) == nums[i])
        {
          ret = true;
          break;
        }
      }
    }
    if (ret == true)
      break;
  }
  free(tbl);
  return ret;
}

void test1(bool(*func)(int*, int))
{
  printf("test1: ");
  int nums[] = {1, 2, 3, 1};
  printf("%d\n", func(nums, 4));
}

void test2(bool(*func)(int*, int))
{
  printf("test2: ");
  int nums[] = {1, 2, 3};
  printf("%d\n", func(nums, 3));
}

void test3(bool(*func)(int*, int))
{
  printf("test3: ");
  int nums[] = {3, 1};
  printf("%d\n", func(nums, 2));
}

void test4(bool(*func)(int*, int))
{
  printf("test4: ");
  int nums[] = {1, 5, -2, -4, 0};
  printf("%d\n", func(nums, 5));
}

void test5(bool(*func)(int*, int))
{
  printf("test5: ");
  int nums[] = {2, 14, 18, 22, 22};
  printf("%d\n", func(nums, 5));
}

void test6(bool(*func)(int*, int))
{
  printf("test6: ");
  int nums[] = {-1200000005,-1200000005};
  printf("%d\n", func(nums, 2));
}



int main()
{
  /* test1(contains_duplicate); */
  /* test2(contains_duplicate); */
  test1(contains_duplicate2);
  test2(contains_duplicate2);
  test3(contains_duplicate2);
  test4(contains_duplicate2);
  test5(contains_duplicate2);
  test6(contains_duplicate2);
  return 0;
}
