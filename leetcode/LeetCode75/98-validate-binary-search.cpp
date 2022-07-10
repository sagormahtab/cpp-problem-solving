#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool BSTUtils(TreeNode *node, long min, long max)
{
  if (node == NULL)
    return true;
  if (node->val <= min || node->val >= max)
    return false;
  return BSTUtils(node->left, min, node->val) && BSTUtils(node->right, node->val, max);
}

bool isValidBST(TreeNode *root)
{
  return BSTUtils(root, LONG_MIN, LONG_MAX);
}

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(6);
  bool result = isValidBST(root);
  cout << result;
  return 0;
}