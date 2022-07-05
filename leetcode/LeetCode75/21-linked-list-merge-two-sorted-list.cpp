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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  if (list1 == NULL)
  {
    return list2;
  }
  if (list2 == NULL)
  {
    return list1;
  }
  ListNode *p1 = list1;
  ListNode *p2 = list2;
  ListNode *list3 = new ListNode;
  ListNode *head = list3;
  while (p1 != NULL || p2 != NULL)
  {
    if (p1 == NULL || p1->val > p2->val)
    {
      head->val = p2->val;
      p2 = p2->next;
    }
    else
    {
      head->val = p1->val;
      p1 = p1->next;
    }

    if (p1 == NULL && p2 == NULL)
    {
      head->next = nullptr;
      head = head->next;
      break;
    }

    head->next = new ListNode;
    head = head->next;
  }

  // This is not possible we can assing NULL only to the ptr -> next
  // head = nullptr or NULL
  return list3;
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
