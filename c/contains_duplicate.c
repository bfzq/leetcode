#include <stdio.h>
#include <stdbool.h>

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

// hash
bool contains_duplicate3(int *nums, int numsSize)
{
  return true;
}

void test1(bool(*func)(int*, int))
{
  int nums[] = {1, 2, 3, 1};
  printf("%d\n", func(nums, 4));
}

void test2(bool(*func)(int*, int))
{
  int nums[] = {1, 2, 3};
  printf("%d\n", func(nums, 3));
}

int main()
{
  test1(contains_duplicate);
  test2(contains_duplicate);
  return 0;
}
