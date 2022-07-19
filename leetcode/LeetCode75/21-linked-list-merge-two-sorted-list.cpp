#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursive Solution
// if (list1 == NULL)
//   return list2;
// if (list2 == NULL)
//   return list1;

// if (list1->val < list2->val)
// {
//   list1->next = mergeTwoLists(list1->next, list2);
//   return list1;
// }
// else
// {
//   list2->next = mergeTwoLists(list1, list2->next);
//   return list2;
// }

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  ListNode *p1 = list1;
  ListNode *p2 = list2;
  ListNode *dummy = new ListNode;
  ListNode *head = dummy;

  while (p1 != NULL && p2 != NULL)
  {
    if (p1->val < p2->val)
    {
      dummy->next = p1;
      p1 = p1->next;
    }
    else
    {
      dummy->next = p2;
      p2 = p2->next;
    }
    dummy = dummy->next;
  }

  if (p1 != NULL)
    dummy->next = p1;

  if (p2 != NULL)
    dummy->next = p2;

  return head->next;
}

int main()
{
  vector<int> list1{1, 2, 4};
  vector<int> list2{1, 3, 4};
  ListNode *l1 = new ListNode;
  ListNode *l1Head = l1;
  ListNode *l2 = new ListNode;
  ListNode *l2Head = l2;

  for (int i = 0; i < list1.size(); i++)
  {
    l1Head->val = list1[i];
    if (i == list1.size() - 1)
    {
      l1Head->next = NULL;
      break;
    }
    l1Head->next = new ListNode(list1[i + 1]);
    l1Head = l1Head->next;
  }

  for (int j = 0; j < list2.size(); j++)
  {
    l2Head->val = list2[j];
    if (j == list2.size() - 1)
    {
      l2Head->next = NULL;
      break;
    }
    l2Head->next = new ListNode(list2[j + 1]);
    l2Head = l2Head->next;
  }

  ListNode *result = mergeTwoLists(l1, l2);
  while (result != NULL)
  {
    cout << result->val;
    result = result->next;
  }
  return 0;
}
