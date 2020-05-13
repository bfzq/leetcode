/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  int inc = 0;
  int number = 0;
  struct ListNode *lst = NULL, *tail = NULL;
  while (l1 != NULL || l2 != NULL || inc != 0)
  {
    if (l1 == NULL && l2 != NULL)
      number = l2->val + inc;
    else if (l2 == NULL && l1 != NULL)
      number = l1->val + inc;
    else if (l1 != NULL && l2 != NULL)
      number = l1->val + l2->val + inc;
    else
      number = inc;
    inc = number / 10;
    number = number % 10;
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = number;
    if (lst == NULL)
    {
      lst = node;
      tail = lst;
    }
    else
    {
      tail->next = node;
      tail = node;
    }
    if (l1 != NULL) l1 = l1->next;
    if (l2 != NULL) l2 = l2->next;
  }
  return lst;
}

int main()
{
  return 0;
}
