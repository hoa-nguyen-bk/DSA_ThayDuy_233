#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};
void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}
void printInteger(int &n)
{
    cout << n << " ";
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    BalanceValue balance;
    Node(const int &val)
    {
        data = val;
        left = right = NULL;
        balance = EH;
    }
};

class AVL
{
private:
    Node *root;

protected:
    Node *rotateRight(Node *&node);
    Node *rotateLeft(Node *&node);
    Node *leftBalance(Node *&node, bool &taller);
    Node *rightBalance(Node *&node, bool &taller);
    // TODO Methods
    Node *insertRec(Node *&node, const int &value, bool &taller);

public:
    AVL()
    {
        this->root = NULL;
    }
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->left);
        int rh = this->getHeightRec(node->right);
        return (lh > rh ? lh : rh) + 1;
    }
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->left);
                q.push(temp->right);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    // TODO Methods
    void insert(const int &value);
    // void remove(const int &value);
};
Node *AVL::rotateRight(Node *&node)
{
    Node *x = node->left;
    node->left = x->right;
    x->right = node;
    return x;
}

Node *AVL::rotateLeft(Node *&node)
{
    Node *y = node->right;
    node->right = y->left;
    y->left = node;
    return y;
}

Node *AVL::rightBalance(Node *&node, bool &taller)
{
    Node *rightTree = node->right;
    if (rightTree->balance == RH)
    {
        node = rotateLeft(node);
        node->balance = EH;
        rightTree->balance = EH;
        node->left->balance = EH;
        taller = false;
    }
    else
    {
        Node *leftTree = rightTree->left;
if (leftTree->balance == RH)
        {
            node->balance = LH;
            rightTree->balance = EH;
        }
        else if (leftTree->balance == EH)
        {
            rightTree->balance = EH;
            node->balance = EH;
        }
        else
        {
            node->balance = EH;
            rightTree->balance = RH;
        }
        leftTree->balance = EH;
        node->right = rotateRight(rightTree);
        node = rotateLeft(node);
        taller = false;
    }
    return node;
}

Node *AVL::leftBalance(Node *&node, bool &taller)
{
    Node *leftTree = node->left;
    // Case 1: Left of left. Single rotation right
    if (leftTree->balance == LH)
    {
        node = rotateRight(node);
        node->balance = EH;
        leftTree->balance = EH;
        node->right->balance = EH;
        taller = false;
    }
    else
    {
        // Right of left. Double rotation required
        Node *rightTree = leftTree->right;
        if (rightTree->balance == LH)
        {
            node->balance = RH;
            leftTree->balance = EH;
        }
        else if (rightTree->balance == EH)
        {
            leftTree->balance = EH;
            node->balance = EH;
        }
        else
        {
            node->balance = EH;
            leftTree->balance = LH;
        }
        rightTree->balance = EH;
        node->left = rotateLeft(leftTree);
        node = rotateRight(node);
        taller = false;
    }
    return node;
}

Node *AVL::insertRec(Node *&node, const int &value, bool &taller)
{
    if (node == nullptr)
    {
        // Insert at leaf
        node = new Node(value);
        taller = true;
        return node;
    }
    if (value < node->data)
    {
        // Insert into the left subtree
        node->left = insertRec(node->left, value, taller);

        // Left subtree is taller
        if (taller)
        {
            if (node->balance == LH)
            {
                node = leftBalance(node, taller);
            }
            else if (node->balance == EH)
            {
                // Was balanced, now left heavy
                node->balance = LH;
            }
            else
            {
                // Was right heavy, now balanced
                node->balance = EH;
                taller = false;
            }
        }
    }
    else
    {
        // Insert into the right subtree
        node->right = insertRec(node->right, value, taller);
        // Right subtree is taller
        if (taller)
        {
            if (node->balance == LH)
            {
                // Left heavy, now balanced
                node->balance = EH;
                taller = false;
            }
            else if (node->balance == EH)
            {
                // Was balanced, now right heavy
                node->balance = RH;
            }
            else
            {
                // Was left heavy, now balanced
                node = rightBalance(node, taller);
            }
        }
    }
return node;
}

void AVL::insert(const int &value)
{
    bool taller = false;
    this->root = insertRec(root, value, taller);
}
int main()
{
    AVL avlTree;
    const int length = 8;
    int arr[length] = {10, 20, 15, 25, 30, 16, 18, 19};
    for (int i = 0; i < length; i++)
    {
        cout << "----------------------------------" << endl;
        avlTree.insert(arr[i]);
        // Printing the structure of AVL tree
        cout << "AVL Tree Structure:" << endl;
        avlTree.printTreeStructure();
        cout << endl;
    }
    return 0;
}