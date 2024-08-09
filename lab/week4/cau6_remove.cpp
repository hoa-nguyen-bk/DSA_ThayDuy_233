/* In this question, you have to perform delete on AVL tree. Note that: 
- Provided insert function already.
Your task is to implement two functions: remove. You could define one or more functions to achieve this task.*/
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
Node* minValueNode(Node* pNode){
    Node* curr = pNode;
    while (curr && curr->pLeft != NULL){
        curr = curr->pLeft;
    }
    return curr;
}
Node* maxValueNode(Node* pNode){
    Node* curr = pNode;
    while (curr && curr->pRight != NULL){
        curr = curr->pRight;
    }
    return curr;
}
Node* deleteNodeRec(Node* pNode, T key){
    if(!pNode){
        return pNode;
    }
    if(pNode->data < key){
        pNode->pRight = deleteNodeRec(pNode->pRight, key);
    }
    else if(pNode->data > key){
        pNode->pLeft = deleteNodeRec(pNode->pLeft, key);
    }
    else if(pNode->data == key && pNode->pLeft == NULL){
        Node* temp = pNode->pRight;
        free(pNode);
        return temp;
    }
    else if(pNode->data == key && pNode->pRight == NULL){
        Node* temp = pNode->pLeft;
        free(pNode);
        return temp;
    }
    else if(pNode->data == key && pNode->pRight != NULL && pNode->pLeft != NULL){
        Node* temp = maxValueNode(pNode->pLeft);
        pNode->data = temp->data;
        pNode->pLeft = deleteNodeRec(pNode->pLeft, temp->data);
    }
    if (pNode == NULL){
        return pNode;
    }
    int bf = BalanceFactor(pNode);
    if(bf < LH && BalanceFactor(root->pLeft) <= EH){
        return LLRotation(pNode);
    }
    if(bf > RH && BalanceFactor(root->pLeft) >= EH){
        return RRRotation(pNode);
    }
    if(bf < LH && BalanceFactor(root->pLeft) < EH){
        return LRRotation(pNode);
    }
    if(bf > RH && BalanceFactor(root->pLeft) > EH){
        return RLRotation(pNode);
    }
    return pNode;
}
void remove(const T& value){
    this->root = deleteNodeRec(this->root, value);
}