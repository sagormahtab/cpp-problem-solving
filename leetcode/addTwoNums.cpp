#include <iostream>
#include <iomanip>
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
  int i = 0, sum = 0, unit = 1;
  // copy of the initial pointer so that the linked list is not destroyed
  ListNode *p = l1;
  ListNode *q = l2;

  ListNode *l3 = new ListNode;
  ListNode *head = l3;

  while (p != NULL || q != NULL)
  {
    int localSum = 0;
    if (p == NULL)
    {
      localSum += q->val;
    }

    if (q == NULL)
    {
      localSum += p->val;
    }
    localSum += p->val + q->val;

    cout << p->val << setw(5) << q->val << setw(5) << localSum << endl;
    sum = sum + localSum * unit;

    p = p->next;
    q = q->next;
    unit *= 10;
  }

  string sumStr = to_string(sum);
  cout << sumStr << endl;
  //   for(int i = sumStr.length(), j = 0; i > -1; i--, j++) {
  //     (l3 + j) -> val = (int) sumStr[i];
  //     if (i == 0) {
  //       (l3 + j) -> next = NULL;
  //     } else {
  //       (l3 + j) -> next = (l3 + j + 1);
  //     }
  //   }
  // cout << l3 -> val;
  //   while (l3 != NULL) {
  //     cout << l3 -> val;
  //     l3 = l3 -> next;
  //   }
  return l1;
};

int main()
{
  // Defining Head
  ListNode *l1Head;
  ListNode *l2Head;

  // Initializing nodes with NULL
  ListNode *l1One = NULL;
  ListNode *l1Two = NULL;
  ListNode *l1Three = NULL;

  ListNode *l2One = NULL;
  ListNode *l2Two = NULL;
  ListNode *l2Three = NULL;

  // allocate nodes in the heap
  l1One = new ListNode;
  l1Two = new ListNode;
  l1Three = new ListNode;

  l2One = new ListNode;
  l2Two = new ListNode;
  l2Three = new ListNode;

  // Assign val values
  l1One->val = 2;
  l1Two->val = 4;
  l1Three->val = 3;

  l2One->val = 5;
  l2Two->val = 6;
  l2Three->val = 4;

  // Connect Nodes
  l1One->next = l1Two;
  l1Two->next = l1Three;
  l1Three->next = NULL;

  l2One->next = l2Two;
  l2Two->next = l2Three;
  l2Three->next = NULL;

  // Connect with head
  l1Head = l1One;
  l2Head = l2One;

  ListNode *result = addTwoNumbers(l1Head, l2Head);
  return 0;
}
