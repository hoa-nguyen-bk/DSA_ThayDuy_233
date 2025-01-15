#include <iostream>
using namespace std;
#include <stdexcept>
#include <sstream>

//**********************
//**      START       **
//**********************
class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {}

    void add(int element) {
        Node* newNode = new Node(element);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        count++;
    }

    void add(int index, int element) {
        if (index < 0 || index > count) {
            throw out_of_range("Index out of range");
        }
        Node* newNode = new Node(element);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (count == 0) {
                tail = newNode;
            }
        } else {
            Node* prev = getNode(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
            if (newNode->next == NULL) {
                tail = newNode;
            }
        }
        count++;
    }

    int size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    string toString() {
        stringstream ss;
        ss << "[";
        Node* current = head;
        while (current) {
            ss << current->data;
            if (current->next) {
                ss << ",";
            }
            current = current->next;
        }
        ss << "]";
        return ss.str();
    }

private:
    Node* getNode(int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

public:
    class Node {
    public:
        int data;
        Node* next;

        Node() : next(NULL) {}
        Node(int data) : data(data), next(NULL) {}
    };
};
//**********************
//**       END        **
//**********************
int main() {
    IntSLinkedList list;
    int size = 10;
    for (int index = 0; index < size; index++) {
        list.add(index);
    }

    cout << list.toString() << endl;
    return 0;
}