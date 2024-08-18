#include <iostream>
using namespace std;
//---START---
int interpolationSearch(int arr[], int left, int right, int x)
{
  if (left <= right && x >= arr[left] && x <= arr[right])
  {
    int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
    cout << "We traverse on index: " << pos << endl;
    if (arr[pos] == x)
      return pos;
    if (arr[pos] < x)
      return interpolationSearch(arr, pos + 1, right, x);
    if (arr[pos] > x)
      return interpolationSearch(arr, left, pos - 1, x);
  }
  return -1;
}
//---END---
int main()
{
  int arr[] = {2, 9, 11, 14, 16, 18, 23, 25, 44, 49, 50, 53, 57, 70, 74, 76, 78, 79, 81, 83, 84, 86, 91, 93, 97};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 84;
  int result = interpolationSearch(arr, 0, n - 1, x);
  (result == -1) ? cout << "Element is not present in array"
                 : cout << "Element is present at index " << result;
  return 0;
}
