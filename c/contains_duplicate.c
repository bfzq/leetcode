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
    idx = *(nums + i) % numsSize;
    if (idx < 0) idx *= -1;
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
  int nums[] = {1, 2, 3, 1};
  printf("test1: %d\n", func(nums, 4));
}

void test2(bool(*func)(int*, int))
{
  int nums[] = {1, 2, 3};
  printf("test2: %d\n", func(nums, 3));
}

void test3(bool(*func)(int*, int))
{
  int nums[] = {3, 1};
  printf("test3: %d\n", func(nums, 2));
}

void test4(bool(*func)(int*, int))
{
  int nums[] = {1, 5, -2, -4, 0};
  printf("test4: %d\n", func(nums, 5));
}

void test5(bool(*func)(int*, int))
{
  int nums[] = {2, 14, 18, 22, 22};
  printf("test5: %d\n", func(nums, 5));
}

void test6(bool(*func)(int*, int))
{
  int nums[] = {-1200000005,-1200000005};
  printf("test6: %d\n", func(nums, 2));
}



int main()
{
  /* test1(contains_duplicate); */
  /* test2(contains_duplicate); */
  test1(contains_duplicate3);
  test2(contains_duplicate3);
  test3(contains_duplicate3);
  test4(contains_duplicate3);
  test5(contains_duplicate3);
  test6(contains_duplicate3);
  return 0;
}
