#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
  /* Function to print an array */
  static void printArray(T *start, T *end)
  {
    int size = end - start;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << ", ";
    cout << start[size - 1];
    cout << endl;
  }

  static void selectionSort(T *start, T *end);
};
//________Start copy________
template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
  int size = end - start;
  int *arr = start;
  int soSanhCost = 0;
  int swapCost = 0;
  for (int st = 0; st < size - 1; ++st)
  {

    int min_idx = st;
    for (int i = min_idx + 1; i < size; ++i)
    {
      soSanhCost += 6;
      cout << "Lần so sánh thứ: " << soSanhCost / 6 << " với " << arr[min_idx] <<" và "<< arr[i]  << endl;
      if (arr[min_idx] > arr[i])
      {
        min_idx = i;
      }
    }
    swapCost += 12;
    swap(arr[st], arr[min_idx]);

    cout << "Lần swap thứ: " << swapCost / 12 << endl;
    cout << "cost = " << swapCost + soSanhCost << endl;
    printArray(start, end);
  }
}
//________End copy________

int main()
{
  const int length = 7;
  int arr[length] = {37,27,43,3,9,82,10};
  
  Sorting<int>::selectionSort(&arr[0], &arr[length-1]);
  return 0;
}
