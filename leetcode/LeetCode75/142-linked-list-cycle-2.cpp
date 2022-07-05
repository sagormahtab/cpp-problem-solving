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

// There are several solutions.Like, Using unordered_set(hashmap) and Floyd's
// This is Floyd's cycle detection algorithm (or, hare and tortoise algorithm).
// Idea is slow increments by 1 and fast by 2 and eventually they meet
ListNode *detectCycle(ListNode *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }

  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      slow = head;
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return NULL;
}

int main()
{
  vector<int> list{3, 2, 0, -4};
  ListNode *l = new ListNode;
  ListNode *lHead = l;
  ListNode *temp = l;

  for (int i = 0; i < list.size(); i++)
  {
    temp->val = list[i];
    if (i == list.size() - 1)
    {
      temp->next = lHead->next;
      break;
    }
    temp->next = new ListNode;
    temp = temp->next;
  }

  ListNode *result = detectCycle(lHead);
  for (int i = 0; i < 8; i++)
  {
    cout << result->val;
    result = result->next;
  }
  return 0;
}
