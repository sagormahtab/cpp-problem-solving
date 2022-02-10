#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  cout << l1 -> next -> next -> val;
  return l1;
};

int main()
{
  struct ListNode* l1 = (struct ListNode*)malloc(3 * sizeof(struct ListNode*));
  struct ListNode* l2 = (struct ListNode*)malloc(3 * sizeof(struct ListNode*));

  l1 -> val = 2;
  l1 -> next = (l1 + 1);

  (l1 + 1) -> val = 4;
  (l1 + 1) -> next = (l1 + 2);

  (l1 + 2) -> val = 3;
  (l1 + 2) -> next = NULL;

  l2 -> val = 5;
  l2 -> next = (l2 + 1);

  (l2 + 1) -> val = 6;
  (l2 + 1) -> next = (l2 + 2);

  (l2 + 2) -> val = 4;
  (l2 + 2) -> next = NULL;

  struct ListNode* result = addTwoNumbers(l1, l2);
  return 0;
}
