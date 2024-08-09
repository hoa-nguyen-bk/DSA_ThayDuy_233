/*In this question, you have to perform add on AVL tree. Note that:
- When adding a node which has the same value as parent node, add it in the right sub tree.*/
int BalanceFactor(Node* pNode){
    if(pNode==NULL) return 0;
    return getHeightRec(pNode->pRight) - getHeightRec(pNode->pLeft);
}
Node* LLRotation(Node* pNode){
    Node* plNode = pNode->pLeft;
    Node* plrNode = plNode->pRight;
    plNode->pRight = pNode;
    pNode->pLeft = plrNode;
    if(root == pNode){
        root = plNode;
    }
    return plNode;
}

Node* RRRotation(Node* pNode){
    Node* prNode = pNode->pRight;
    Node* prlNode = prNode->pLeft;
    prNode->pLeft = pNode;
    pNode->pRight = prlNode;
    if(root == pNode){
        root = prNode;
    }
    return prNode;
}
Node* LRRotation(Node* pNode){
    pNode->pLeft = RRRotation(pNode->pLeft);
    return LLRotation(pNode);       
}
Node* RLRotation(Node* pNode){
    pNode->pRight = LLRotation(pNode->pRight);
    return RRRotation(pNode);
}
Node* insertNode(Node* pNode, T key){
    if(!pNode){
        Node* newNode = new Node(key);
        return newNode;
    }
    if(key < pNode->data){
        pNode->pLeft = insertNode(pNode->pLeft, key);
    }
    else if(key >= pNode->data){
        pNode->pRight = insertNode(pNode->pRight, key);
    }
    int bf = BalanceFactor(pNode);
    //LL Rotation
    if(bf < LH && key < pNode->pLeft->data){
        return LLRotation(pNode);
    }
    //RR Rotation
    if(bf > RH && key >= pNode->pRight->data){
        return RRRotation(pNode);
    }
    //LR Rotation
    if(bf < LH && key >= pNode->pLeft->data){
        return LRRotation(pNode);
    }
    //RL Rotation
    if(bf > RH && key < pNode->pRight->data){
        return RLRotation(pNode);
    }
    return pNode;
}
void insert(const T &value){
    this->root = insertNode(this->root, value);
}