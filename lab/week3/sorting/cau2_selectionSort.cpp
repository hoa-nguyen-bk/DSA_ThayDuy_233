#include "./../header/Sorting_cau2.h"
//---START---
template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
  int size = end - start;
  int *arr = start;

  for (int st = 0; st < size - 1; ++st)
  {
    int min_idx = st;
    for (int i = min_idx + 1; i < size; ++i)
    {
      if (arr[min_idx] > arr[i])
        min_idx = i;
    }
    swap(arr[st], arr[min_idx]);
    printArray(start, end);
  }
}
//---END---
int main()
{
  int arr[] = {9, 2, 8, 1, 0, -2};
Sorting<int>::selectionSort(&arr[0], &arr[6]);
// -2, 2, 8, 1, 0, 9
// -2, 0, 8, 1, 2, 9
// -2, 0, 1, 8, 2, 9
// -2, 0, 1, 2, 8, 9
// -2, 0, 1, 2, 8, 9

  return 0;
}
