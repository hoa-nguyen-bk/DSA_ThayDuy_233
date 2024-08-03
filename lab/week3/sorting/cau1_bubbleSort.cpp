
#include "./../header/SLinkedList.h"
//---START---
template <class T>
void SLinkedList<T>::bubbleSort()
{
  if (this->count == 0 || this->count == 1)
    return;
  Node *unsorted = this->head;
  Node *sorted = this->tail->next;
  Node *sentinel = sorted;
  bool isSwapped = true;

  while (isSwapped)
  {
    sentinel = sorted;
    isSwapped = false;
    unsorted = this->head;
    while (unsorted->next != sorted)
    {
      if (unsorted->data > unsorted->next->data)
      {
        T temp = unsorted->data;
        unsorted->data = unsorted->next->data;
        unsorted->next->data = temp;
        isSwapped = true;
      }
      unsorted = unsorted->next;
    }

    sorted = this->head;
    while (sorted->next != sentinel)
      sorted = sorted->next;
    if (isSwapped)
      this->printList();
  }
}
//---END---
int main()
{
  int arr[] = {9, 2, 8, 4, 1};
  SLinkedList<int> list;
  for (int i = 0; i < int(sizeof(arr)) / 4; i++)
    list.add(arr[i]);
  list.bubbleSort();
  // [2,8,4,1,9]
  // [2,4,1,8,9]
  // [2,1,4,8,9]
  // [1,2,4,8,9]
  return 0;
}
