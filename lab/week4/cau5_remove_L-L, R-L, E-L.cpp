/** * In this question, you have to perform delete in AVL tree - balanced, L-L, R-L, E-L. Note that: 
- Provided insert function already.
Your task is to implement function: remove to perform re-balancing (balanced, left of left, right of left, equal of left). You could define one or more functions to achieve this task.
*/
Node *rightRotate(Node *main){
    Node *Left_child = main->pLeft;
    Node *Right_child_of_leftchild = Left_child->pRight;
    Left_child->pRight = main;
    main->pLeft = Right_child_of_leftchild;
    return Left_child;
}
Node *leftRotate(Node *main){
    Node *Right_child = main->pRight;
    Node *Left_child_of_rightchild = Right_child->pLeft;
    Right_child->pLeft = main;
    main->pRight = Left_child_of_rightchild;
    return Right_child;
}
int getBalance(Node *N){
    if (N == NULL){
      return 0;
    }
    return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
}
Node *maxValueNode(Node *main){
    Node *current = main;
    while (current->pRight != NULL)
      current = current->pRight;
    return current;
}
Node *remove_helper(Node *root, int key){
    if (root == NULL)
      return root;
    if (key < root->data)
      root->pLeft = remove_helper(root->pLeft, key);
    else if (key > root->data)
      root->pRight = remove_helper(root->pRight, key);
    else {
      if ((root->pLeft == NULL) || (root->pRight == NULL)){
        Node *temp = root->pLeft ? root->pLeft : root->pRight;
        if (temp == NULL){
          temp = root;
          root = NULL;
        } else{
          *root = *temp; // Copy the contents of
        }             // One child case
        free(temp);
      } else {
        Node *temp = maxValueNode(root->pLeft);
        root->data = temp->data;
        root->pLeft = remove_helper(root->pLeft, temp->data);
      }
    }
    if (root == NULL){
        return root;
    }
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->pLeft) >= 0)
      return rightRotate(root);
    if (balance > 1 && getBalance(root->pLeft) < 0){
      root->pLeft = leftRotate(root->pLeft);
      return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->pRight) <= 0)
      return leftRotate(root);
    if (balance < -1 && getBalance(root->pRight) > 0)
    {
      root->pRight = rightRotate(root->pRight);
      return leftRotate(root);
    }
    return root;
}
void remove(const T &value){
    this->root = remove_helper(root, value);
}