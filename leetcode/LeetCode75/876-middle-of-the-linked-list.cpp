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

// There are two solutions. One pass and Two pass
// This is one pass as we are traversing the list once.
// Idea is slow increments by 1 and fast by 2
ListNode *middleNode(ListNode *head)
{
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  head = slow;
  return head;
}

int main()
{
  vector<int> list{1, 2, 3, 4, 5, 6};
  ListNode *l = new ListNode;
  ListNode *lHead = l;
  ListNode *temp = l;

  for (int i = 0; i < list.size(); i++)
  {
    temp->val = list[i];
    if (i == list.size() - 1)
    {
      temp->next = NULL;
      break;
    }
    temp->next = new ListNode(list[i + 1]);
    temp = temp->next;
  }

  ListNode *result = middleNode(lHead);
  while (result != NULL)
  {
    cout << result->val;
    result = result->next;
  }
  return 0;
}
