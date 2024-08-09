/*In this question, you have to search and print inorder on AVL tree. You have o implement functions: search and printInorder to complete the task. Note that:
- When the tree is null, don't print anything. 
- There's a whitespace at the end when print the tree inorder in case the tree is not null.
- When tree contains value, search return true.*/
void inOrder(Node *&root){
    if (root != nullptr){
        inOrder(root->pLeft);
        cout << root->data << " ";
        inOrder(root->pRight);
    }
    return;
}
void printInorder(){
    inOrder(this->root);
}
Node *searchBST(Node *&root, T target){
    if (root == nullptr)
      return nullptr;
    if (target < root->data)
      return searchBST(root->pLeft, target);
    else if (target < root->data)
      return searchBST(root->pRight, target);
    else
      return root;
}
bool search(const T &value){
    Node *findingNode = searchBST(this->root, value);
    if (findingNode == nullptr){
      return false;
    }
    return true;
}