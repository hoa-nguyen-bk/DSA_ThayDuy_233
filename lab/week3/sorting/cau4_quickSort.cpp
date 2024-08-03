#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting
{
private:
  //---START---
  static T *Partition(T *start, T *end)
  {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T pivot = *start;
    T *left = start + 1;
    T *right = end - 1;

    while (true)
    {
      while (left <= right && *left >= pivot) // Change to descending order
        left++;
      while (left <= right && *right < pivot) // Change to descending order
        right--;
      if (left > right)
        break;
      std::swap(*left, *right);
      left++;
      right--;
    }
    std::swap(*start, *right);
    return right;
  }

public:
  static void QuickSort(T *start, T *end)
  {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if (start < end)
    {
      T *pivotIndex = Partition(start, end);
      std::cout << pivotIndex - start << " "; // Print index of pivot
      QuickSort(start, pivotIndex);
      QuickSort(pivotIndex + 1, end);
    }
  }
  //---END---
};
int main()
{
  int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
  cout << "Index of pivots: ";
  Sorting<int>::QuickSort(&array[0], &array[20]);
  cout << "\n";
  cout << "Array after sorting: ";
  for (int i : array)
    cout << i << " ";
  // Index of pivots: 17 2 1 0 7 6 1 0 1 0 0 0 3 0 1 0 0 0 0 0
  // Array after sorting: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

  return 0;
}
