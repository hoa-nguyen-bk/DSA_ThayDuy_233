// Implement functions: Peek, Pop, Size, Empty, Contains to a maxHeap. If the function cannot execute, return -1.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template <class T>
class Heap
{
protected:
  T *elements;
  int capacity;
  int count;

public:
  Heap()
  {
    this->capacity = 10;
    this->count = 0;
    this->elements = new T[capacity];
  }
  ~Heap()
  {
    delete[] elements;
  }
  void push(T item);
  bool isEmpty();
  bool contains(T item);
  T peek();
  bool pop();
  int size();
  void printHeap()
  {
    cout << "Max Heap [ ";
    for (int i = 0; i < count; i++)
      cout << elements[i] << " ";
    cout << "]\n";
  }

private:
  void ensureCapacity(int minCapacity);
  void reheapUp(int position);
  void reheapDown(int position);
};

//---START---

//---END---
int main()
{

  return 0;
}
