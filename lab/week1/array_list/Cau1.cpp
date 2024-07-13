/*
The prices of all cars of a car shop have been saved as an array called N. Each element of the array N is the price of
each car in shop. A person, with the amount of money k want to buy as much cars as possible.
Request: Implement function
buyCar(int* nums, int length, int k);
Where nums is the array N, length is the size of this array and k is the amount of money the person has. Find the
maximum cars this person can buy with his money, and return that number.
Example:
nums=[90, 30, 20, 40, 50]; k=90;
The result is 3, he can buy the cars having index 1, 2, 3 (first index is 0).
Note: The library iostream, 'algorithm' and using namespace std have been used. You can add other functions but you
are not allowed to add other libraries.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int buyCar(int *nums, int length, int k)
{
  // Bước 1: sắp xếp lại cái đã, giống bài toán cái túi
  sort(nums, nums + length);

  int maxCars = 0;
  int curentCost = 0;

  for (int i = 0; i < length; i++)
  {
    if (curentCost + nums[i] <= k)
    {
      curentCost += nums[i];
      maxCars++;
    }
    else
    {
      break;
    }
  }
  return maxCars;
}
int main()
{
  int nums[] = {90, 30, 40, 90, 20};
  int length = sizeof(nums) / sizeof(nums[0]);
  cout << buyCar(nums, length, 90) << "\n";
  // 3
  return 0;
}
