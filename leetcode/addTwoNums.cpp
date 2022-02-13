#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  int unit = 1, sum = 0, carry = 0;
  // copy of the initial pointer so that the linked list is not destroyed
  ListNode *p = l1;
  ListNode *q = l2;

  ListNode *l3 = new ListNode;
  ListNode *head = l3;
  ListNode *r = head;

  while (p != NULL || q != NULL)
  {
    int localSum = 0;
    if (p == NULL)
    {
      localSum = q->val + carry;
      r->val = localSum % 10;
      q = q->next;
    }
    else if (q == NULL)
    {
      localSum = p->val + carry;
      r->val = localSum % 10;
      p = p->next;
    }
    else
    {
      localSum = (p->val + q->val + carry);
      p = p->next;
      q = q->next;
      r->val = localSum % 10;
    }

    carry = localSum / 10;

    if (p == NULL && q == NULL)
    {
      if (carry == 1)
      {
        r->next = new ListNode(carry);
        break;
      }
      r->next = NULL;
      break;
    }

    r->next = new ListNode;
    r = r->next;
  }

  return head;
};

int main()
{
  vector<int> list1{2, 4};
  vector<int> list2{5, 6, 9};

  // Generating l1 linked list
  ListNode *l1 = new ListNode;
  ListNode *l1Head = l1;
  ListNode *p = l1Head;

  for (int i = 0; i < list1.size(); i++)
  {
    p->val = list1[i];
    if (i == list1.size() - 1)
    {
      p->next = NULL;
      break;
    }
    p->next = new ListNode(list1[i + 1]);
    p = p->next;
  }

  // Generating l2 linked list
  ListNode *l2 = new ListNode;
  ListNode *l2Head = l2;
  ListNode *q = l2Head;

  for (int i = 0; i < list2.size(); i++)
  {
    q->val = list2[i];
    if (i == list2.size() - 1)
    {
      q->next = NULL;
      break;
    }
    q->next = new ListNode(list2[i + 1]);
    q = q->next;
  }

  ListNode *result = addTwoNumbers(l1Head, l2Head);
  while (result != NULL)
  {
    cout << result->val;
    result = result->next;
  }
  return 0;
}
