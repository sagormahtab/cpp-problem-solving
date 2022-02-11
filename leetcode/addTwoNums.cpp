#include <iostream>
#include <iomanip>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int i = 0, sum = 0, unit = 1;
  // ListNode *l3 = new ListNode;
  // struct ListNode* l3 = (struct ListNode*)malloc(3 * sizeof(struct ListNode*));

  // while (l1 != NULL) {
  //   cout << l1 -> val;
  //   l1 = l1 -> next;
  // }

  while(l1 != NULL || l2 != NULL) {
    int localSum = 0;
    if (l1 -> val == NULL) {
      localSum += l2 -> val;
    }

    if (l2 -> val == NULL) {
      localSum += l1 -> val;
    }
    localSum += l1 -> val + l2 -> val;

    cout << l1 -> val << setw(5) << l2 -> val << setw(5) << localSum << endl;
    sum = sum + localSum * unit;
  
    l1 = l1 -> next;
    l2 = l2 -> next;
    unit *= 10;
  }
  cout << sum;
  string sumStr = to_string(sum);
  ListNode* l3 = (ListNode*)malloc(sizeof(ListNode*));
  cout << "bruh"<< sumStr << endl;
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
  ListNode* l1 = (ListNode*)malloc(4 * sizeof(ListNode*));
  ListNode* l2 = (ListNode*)malloc(4 * sizeof(ListNode*));

  cout << l1 << endl << l2 << endl;
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
