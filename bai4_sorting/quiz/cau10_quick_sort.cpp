#include <iostream>
#include <algorithm>

using namespace std;
int countSwap = 0;
int partition(int arr[], int low, int high)
{
  // choose the pivot

  int pivot = arr[low];
  cout << "pivot = " << pivot << endl;
  // Index of smaller element and Indicate
  // the right position of pivot found so far
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    countSwap++;
    // If current element is smaller than the pivot
    if (arr[j] < pivot)
    {
      // Increment index of smaller element
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

// The Quicksort function Implement

void quickSort(int arr[], int low, int high)
{
  // when low is less than high
  if (low < high)
  {
    // pi is the partition return index of pivot

    int pi = partition(arr, low, high);

    // Recursion Call
    // smaller element than pivot goes left and
    // higher element goes right
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    cout<<"\n In mảng: ";
    for (int i = 0; i < high - low; i++)
    {
      cout << arr[i]<<"-";
    }
  }
}

int main()
{
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr) / sizeof(arr[0]);
  // Function call
  quickSort(arr, 0, n - 1);
  // Print the sorted array
  cout << "\ncount = " << countSwap << endl;
  cout << "Sorted Array\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
// This Code is Contributed By Diwakar Jha
