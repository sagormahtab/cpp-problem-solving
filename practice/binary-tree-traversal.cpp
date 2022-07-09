#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int val;
  Node *left;
  Node *right;
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void pre_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->val << " ";
  pre_order(root->left);
  pre_order(root->right);
}

void in_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}

void post_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  post_order(root->left);
  cout << root->val << " ";
  post_order(root->right);
}

/*
         1
      /    \
      2     3
    / \    /  \
  4    5  6   7
*/

int main()
{
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  Node *root = new Node(v[0]);

  root->left = new Node(v[1]);
  root->right = new Node(v[2]);
  root->left->left = new Node(v[3]);
  root->left->right = new Node(v[4]);
  root->right->left = new Node(v[5]);
  root->right->right = new Node(v[6]);
  cout << "Pre order: ";
  pre_order(root);
  cout << endl
       << "In order: ";
  in_order(root);
  cout << endl
       << "Post order: ";
  post_order(root);
  return 0;
}