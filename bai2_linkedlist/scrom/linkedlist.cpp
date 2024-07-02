#include "listADT.h"

// template <class T>
// struct NodeWithStruct{
//   int data;
//   Node *linknext;
// };

class IntSingleLinkedList:public IList<int>{
  public:
    class Node;
  
  protected:
    Node* head;
    Node* tail;
    int count;

  public:
    IntSingleLinkedList():
      head(NULL), tail(NULL), count(0) {};
  
  public:
    class Node{
      protected:
        int data;
        Node *next;
      public:
        Node(int data = 0){
          int data = 0;
          this->next=NULL;
        }
    };
};