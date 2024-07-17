#include <iostream>
#include <string>
using namespace std;

template <class T>
class DLinkedList
{
public:
  class Iterator; // forward declaration
  class Node;     // forward declaration

protected:
  Node *head;
  Node *tail;
  int count;

public:
  DLinkedList() : head(NULL), tail(NULL), count(0) {};
  ~DLinkedList();
  void add(const T &e);
  void add(int index, const T &e);
  T removeAt(int index);
  bool removeItem(const T &item);
  bool empty();
  int size();
  void clear();
  T get(int index);
  void set(int index, const T &e);
  int indexOf(const T &item);
  bool contains(const T &item);
  string toString();
  Iterator begin()
  {
    return Iterator(this, true);
  }
  Iterator end()
  {
    return Iterator(this, false);
  }

public:
  class Node
  {
  private:
    T data;
    Node *next;
    Node *previous;
    friend class DLinkedList<T>;

  public:
    Node()
    {
      this->previous = NULL;
      this->next = NULL;
    }

    Node(const T &data)
    {
      this->data = data;
      this->previous = NULL;
      this->next = NULL;
    }
  };

  class Iterator
  {
  private:
    DLinkedList<T> *pList;
    Node *current;
    int index; // is the index of current in pList

  public:
    Iterator(DLinkedList<T> *pList, bool begin)
    {
      this->pList = pList;
      if (begin)
      {
        this->current = pList->head;
        this->index = 0;
      }
      else
      {
        this->current = NULL;
        this->index = pList->count;
      }
    }

    Iterator &operator=(const Iterator &iterator)
    {
      this->pList = iterator.pList;
      this->current = iterator.current;
      this->index = iterator.index;
      return *this;
    }

    void set(const T &e)
    {
      if (this->current != NULL)
        this->current->data = e;
    }

    T &operator*()
    {
      return this->current->data;
    }

    bool operator!=(const Iterator &iterator)
    {
      return this->current != iterator.current;
    }

    void remove()
    {
      if (this->current == NULL)
        return;

      Node *toDelete = this->current;
      if (toDelete->previous != NULL)
      {
        toDelete->previous->next = toDelete->next;
      }
      else
      {
        this->pList->head = toDelete->next;
      }

      if (toDelete->next != NULL)
      {
        toDelete->next->previous = toDelete->previous;
      }
      else
      {
        this->pList->tail = toDelete->previous;
      }

      this->current = toDelete->next;
      delete toDelete;
      this->pList->count--;
    }

    // Prefix ++ overload
    Iterator &operator++()
    {
      if (this->current != NULL)
      {
        this->current = this->current->next;
        this->index++;
      }
      return *this;
    }

    // Postfix ++ overload
    Iterator operator++(int)
    {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }
  };
};

template <class T>
DLinkedList<T>::~DLinkedList()
{
  clear();
}

template <class T>
void DLinkedList<T>::add(const T &e)
{
  Node *newNode = new Node(e);
  if (tail == NULL)
  {
    head = tail = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
  }
  count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
  if (index < 0 || index > count)
    throw out_of_range("Index out of range");

  Node *newNode = new Node(e);
  if (index == 0)
  {
    newNode->next = head;
    if (head != NULL)
      head->previous = newNode;
    head = newNode;
    if (tail == NULL)
      tail = newNode;
  }
  else if (index == count)
  {
    tail->next = newNode;
    newNode->previous = tail;
    tail = newNode;
  }
  else
  {
    Node *current = head;
    for (int i = 0; i < index; i++)
      current = current->next;
    newNode->next = current;
    newNode->previous = current->previous;
    current->previous->next = newNode;
    current->previous = newNode;
  }
  count++;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
  if (index < 0 || index >= count)
    throw out_of_range("Index out of range");

  Node *toDelete = head;
  for (int i = 0; i < index; i++)
    toDelete = toDelete->next;

  T data = toDelete->data;
  if (toDelete->previous != NULL)
  {
    toDelete->previous->next = toDelete->next;
  }
  else
  {
    head = toDelete->next;
  }

  if (toDelete->next != NULL)
  {
    toDelete->next->previous = toDelete->previous;
  }
  else
  {
    tail = toDelete->previous;
  }

  delete toDelete;
  count--;
  return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
  Node *current = head;
  while (current != NULL)
  {
    if (current->data == item)
    {
      if (current->previous != NULL)
      {
        current->previous->next = current->next;
      }
      else
      {
        head = current->next;
      }

      if (current->next != NULL)
      {
        current->next->previous = current->previous;
      }
      else
      {
        tail = current->previous;
      }

      delete current;
      count--;
      return true;
    }
    current = current->next;
  }
  return false;
}

template <class T>
bool DLinkedList<T>::empty()
{
  return count == 0;
}

template <class T>
int DLinkedList<T>::size()
{
  return count;
}

template <class T>
void DLinkedList<T>::clear()
{
  while (head != NULL)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  tail = NULL;
  count = 0;
}

template <class T>
T DLinkedList<T>::get(int index)
{
  if (index < 0 || index >= count)
    throw out_of_range("Index out of range");

  Node *current = head;
  for (int i = 0; i < index; i++)
    current = current->next;
  return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
  if (index < 0 || index >= count)
    throw out_of_range("Index out of range");

  Node *current = head;
  for (int i = 0; i < index; i++)
    current = current->next;
  current->data = e;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
  Node *current = head;
  int index = 0;
  while (current != NULL)
  {
    if (current->data == item)
      return index;
    current = current->next;
    index++;
  }
  return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
  return indexOf(item) != -1;
}

template <class T>
string DLinkedList<T>::toString()
{
  string result = "[";
  Node *current = head;
  while (current != NULL)
  {
    result += to_string(current->data);
    if (current->next != NULL)
      result += ", ";
    current = current->next;
  }
  result += "]";
  return result;
}

int main()
{
  DLinkedList<int> list;
  int size = 10;
  for (int idx = 0; idx < size; idx++)
  {
    list.add(idx);
  }
  DLinkedList<int>::Iterator it = list.begin();
  for (; it != list.end(); it++)
  {
    cout << *it << " |";
  }
  cout << endl;

  DLinkedList<int> list2;
  for (int idx = 0; idx < size; idx++)
  {
    list2.add(idx);
  }

  DLinkedList<int>::Iterator it2 = list2.begin();
  while (it2 != list2.end())
  {
    it2.remove();
    it2++;
  }
  cout << list2.toString() << endl;

  DLinkedList<int> list3;
  for (int idx = 0; idx < size; idx++)
  {
    list3.add(idx);
  }

  DLinkedList<int>::Iterator it3 = list3.begin();
  for (; it3 != list3.end(); it3++)
  {
    it3.remove();
  }
  cout << list3.toString() << endl;

  return 0;
}