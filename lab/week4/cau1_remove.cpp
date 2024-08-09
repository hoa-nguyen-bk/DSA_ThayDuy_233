/*In this question, you have to perform rotate nodes on AVL tree. Note that:
- When adding a node which has the same value as parent node, add it in the right sub tree.
Your task is to implement function: rotateRight, rotateLeft. You could define one or more functions to achieve this task.*/
Node* insertRec(Node* node, const T &value) {
    if (node == NULL) {
        return new Node(value);
    }
    if (value < node->data) {
        node->pLeft = insertRec(node->pLeft, value);
    } else {
        node->pRight = insertRec(node->pRight, value);
    }
    node = balanceNode(node);
    return node;
}
Node* rotateRight(Node* subroot) {
    Node* newRoot = subroot->pLeft;
    subroot->pLeft = newRoot->pRight;
    newRoot->pRight = subroot;
    return newRoot;
}
Node* rotateLeft(Node* subroot) {
    Node* newRoot = subroot->pRight;
    subroot->pRight = newRoot->pLeft;
    newRoot->pLeft = subroot;
    return newRoot;
}
Node* balanceNode(Node* node) {
    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->pLeft) < 0) {
            node->pLeft = rotateLeft(node->pLeft);
        }
        return rotateRight(node);
    }
    if (balance < -1) {
        if (getBalance(node->pRight) > 0) {
            node->pRight = rotateRight(node->pRight);
        }
        return rotateLeft(node);
    }

    return node;
}