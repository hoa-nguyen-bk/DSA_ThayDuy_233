#include <iostream>
using namespace std;
//---START---
int binarySearch(int arr[], int left, int right, int x)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;
    cout << "We traverse on index: " << mid << endl;
    if (arr[mid] == x)
    {
      return mid;
    }
    if (arr[mid] > x)
      return binarySearch(arr, left, mid - 1, x);
    return binarySearch(arr, mid + 1, right, x);
  }
  return -1;
}
//---END---
int main()
{
  int arr[] = {2, 9, 11, 14, 16, 18, 23, 25, 44, 49, 50, 53, 57, 70, 74, 76, 78, 79, 81, 83, 84, 86, 91, 93, 97};
  int x = 84;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) ? cout << "Element is not present in array"
                 : cout << "Element is present at index " << result;
  return 0;
}
