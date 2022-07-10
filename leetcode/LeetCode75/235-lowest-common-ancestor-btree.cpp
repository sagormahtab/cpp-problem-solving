#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
  if ((root->val > p->val) && (root->val > q->val))
    return lowestCommonAncestor(root->left, p, q);
  if ((root->val < p->val) && (root->val < q->val))
    return lowestCommonAncestor(root->right, p, q);
  return root;
}

int main()
{
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  TreeNode *p = new TreeNode(2);
  TreeNode *q = new TreeNode(8);
  TreeNode *result = lowestCommonAncestor(root, p, q);
  cout << result->val;
  return 0;
}