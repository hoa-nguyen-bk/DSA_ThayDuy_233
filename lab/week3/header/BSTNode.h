class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
    static BSTNode *createBSTree(int *begin, int *end)
  {
    if (begin == end)
    {
      return nullptr;
    }
    int *mid = begin + (end - begin) / 2;
    BSTNode *root = new BSTNode(*mid);
    root->left = createBSTree(begin, mid);
    root->right = createBSTree(mid + 1, end);
    return root;
  }

  static void deleteTree(BSTNode *root)
  {
    if (root == nullptr)
    {
      return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
};