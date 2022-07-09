#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  vector<Node *> children;

  Node(){};
  Node(int _val)
  {
    val = _val;
  }
  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

// Here loop is the base case. That's why that if is not needed
void preOrderTraversal(Node *root, vector<int> &ans)
{
  // if (root == NULL)
  //   return;
  ans.push_back(root->val);
  for (int i = 0; i < root->children.size(); i++)
  {
    preOrderTraversal(root->children[i], ans);
  }
}

vector<int> preorder(Node *root)
{
  vector<int> result;
  if (root == NULL)
    return result;

  preOrderTraversal(root, result);
  return result;
}

int main()
{
  /*   Let us create below tree
   *              10
   *        /   /    \   \
   *        2  34    56   100
   *       / \         |   /  | \
   *      77  88       1   7  8  9
   */
  Node *root = new Node(10);
  (root->children).push_back(new Node(2));
  (root->children).push_back(new Node(34));
  (root->children).push_back(new Node(56));
  (root->children).push_back(new Node(100));

  (root->children[0]->children).push_back(new Node(77));
  (root->children[0]->children).push_back(new Node(88));
  (root->children[2]->children).push_back(new Node(1));
  (root->children[3]->children).push_back(new Node(7));
  (root->children[3]->children).push_back(new Node(8));
  (root->children[3]->children).push_back(new Node(9));

  vector<int> result = preorder(root);
  for (auto v : result)
    cout << v << " ";
  return 0;
}
