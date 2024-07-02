#include <cstddef>
#include <string>
#include <iostream>

class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {};
    void add(int element) {
        
    }

    void add(int index, int element) {
        
    }

    int removeAt(int index) {

        return 0;
    }

    bool removeItem(int item) {

        return false;
    }

    bool empty() {

        return false;
    }

    int size() {

        return 0;
    }
    
    int get(int index) {
        return -1;
    }

    void set(int index, int element) {

    }

    int indexOf(int item) {
        return -1;
    }

    bool contains(int item) {
        return false;
    }
    
    void clear() {

    }
    
    string toString();

public:
    class Node {
    public:
        int data;
        Node* next;

    public:
        Node() : next(NULL) {};
        Node(int data) : 
            data(data), next(NULL) {};
    };
};