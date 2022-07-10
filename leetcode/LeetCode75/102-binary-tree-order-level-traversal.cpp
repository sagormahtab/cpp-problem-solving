#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root)
{
  vector<vector<int>> result;
  if (root == NULL)
    return result;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    vector<int> temp;
    int n = q.size();
    while (n--)
    {
      TreeNode *curr = q.front();
      q.pop();
      temp.push_back(curr->val);
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    result.push_back(temp);
  }
  return result;
}

int main()
{
  /*   Let us create below tree
   *              3
   *            /   \
   *           9    20
   *               / \
   *             77  88
   */
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(77);
  root->right->right = new TreeNode(88);
  vector<vector<int>> res = levelOrder(root);

  for (const auto &v : res)
  {
    for (auto i : v)
    {
      cout << i << endl;
    }
  }
  return 0;
}