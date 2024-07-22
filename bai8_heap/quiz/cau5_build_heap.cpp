#include <iostream>
// #include "sortingyoutube.h"
using namespace std;


int count_swap = 0;
template <class T>
class Sorting
{
public:
  /* Function to print an array */
  static void printArray(T *start, T *end)
  {
    long size = end - start;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << ", ";
    cout << start[size - 1];
    cout << endl;
  }
  static bool isLeaf(int pos, int count) // True if pos is a leaf
  {
    return (pos >= count / 2) && (pos < count);
  }
  // Helping functions go here
  static void heapify(T *start, T *end, int i)
  {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int n = end - start;

    if (left < n && start[left] > start[largest])
      largest = left;

    if (right < n && start[right] > start[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
      count_swap++;
      swap(start[i], start[largest]);
      heapify(start, end, largest);
    }
  }

  // Helping functions go here
  static void heapSort(T *start, T *end)
  {
    // TODO
    int n = end - start;

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(start, end, i);

    // Print array
    Sorting<T>::printArray(start, end);
  }
};
int main() 
{
  const int length = 15;
  int arr[length] = {21,19,99,89,40,77,88,69,9,87,32,61,18,36,30};
  Sorting<int>::heapSort(&arr[0], &arr[length]);
  cout<<count_swap<<endl;
  return 0;
}
