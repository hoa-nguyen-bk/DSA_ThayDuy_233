#include <iostream>
#include <algorithm> // Include the <algorithm> header for the sort function
#include <sstream>   // Include the <sstream> header for stringstream
using namespace std;
//---START---
string minDiffPairs(int *arr, int n)
{
  sort(arr, arr + n);
  int minDiff = arr[1] - arr[0];
  stringstream result;

  for (int i = 2; i < n; i++)
  {
    minDiff = min(minDiff, arr[i] - arr[i - 1]);
  }

  for (int i = 1; i < n; i++)
  {
    if (arr[i] - arr[i - 1] == minDiff)
    {
      result << "(" << arr[i - 1] << ", " << arr[i] << "), ";
    }
  }

  string resultStr = result.str();
  if (!resultStr.empty())
  {
    resultStr = resultStr.substr(0, resultStr.length() - 2);
  }

  return resultStr;
}
//---END---
int main()
{
  int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
  cout << minDiffPairs(arr, 10);
  // (5, 6), (6, 7), (7, 8), (8, 9), (9, 10), (10, 11), (11, 12)
  return 0;
}
