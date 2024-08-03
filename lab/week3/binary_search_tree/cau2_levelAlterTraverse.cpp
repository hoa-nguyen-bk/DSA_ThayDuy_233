#include <iostream>
#include <vector>
#include "./../header/BSTNode.h"
#include <queue>
#include <stack>
using namespace std;
//---START---
vector<int> levelAlterTraverse(BSTNode *root)
{
  vector<int> result;
  if (root == nullptr)
  {
    return result;
  }
  queue<BSTNode *> q;
  q.push(root);
  bool leftToRight = true;
  while (!q.empty())
  {
    int levelSize = q.size();
    stack<int> s;
    for (int i = 0; i < levelSize; i++)
    {
      BSTNode *node = q.front();
      q.pop();
      if (leftToRight)
      {
        result.push_back(node->val);
      }
      else
      {
        s.push(node->val);
      }
      if (node->left != nullptr)
      {
        q.push(node->left);
      }
      if (node->right != nullptr)
      {
        q.push(node->right);
      }
    }
    leftToRight = !leftToRight;
    while (!s.empty())
    {
      result.push_back(s.top());
      s.pop();
    }
  }
  return result;
}
//---END---

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
  int arr[] = {0, 3, 5, 1, 2, 4};
  BSTNode *root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
  printVector(levelAlterTraverse(root));
  BSTNode::deleteTree(root);
  // [0, 3, 1, 5, 4, 2]

  return 0;
}
