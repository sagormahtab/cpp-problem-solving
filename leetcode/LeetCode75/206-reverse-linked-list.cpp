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

// Idea is to alter the direction from -> to <- of the nodes
// For that transfer next to prev and keep a refererence to next using temp
// and shift the prev and current to the next for the next iteration
ListNode *reverseList(ListNode *head)
{
  ListNode *current = head;
  ListNode *temp = NULL;
  ListNode *prev = NULL;
  while (current != NULL)
  {
    temp = current->next;
    current->next = prev;

    prev = current;
    current = temp;
  }
  // bc shobar last e null
  head = prev;
  return head;
}

int main()
{
  vector<int> list{1, 2, 4};
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

  ListNode *result = reverseList(lHead);
  while (result != NULL)
  {
    cout << result->val;
    result = result->next;
  }
  return 0;
}
