/*
Given an array of integers.
Your task is to implement a function with following prototype:
int equalSumIndex(vector<int>& nums);
The function returns the smallest index i such that the sum of the numbers to the left of i is equal to the sum of the numbers to the right.
If no such index exists, return -1.
*/
#include <iostream>
using namespace std;
#include <vector>
//---START---
int equalSumIndex(vector<int> &nums)
{
  // STUDENT ANSWER
  int totalSum = 0;
  int leftSum = 0;
  for (int num : nums)
  {
    totalSum += num;
  }
  for (int i = 0; i < nums.size(); ++i)
  {
    totalSum -= nums[i];
    if (leftSum == totalSum)
    {
      return i;
    }
    leftSum += nums[i];
  }
  return -1;
}
//---END----
int main()
{
  vector<int> nums{3, 5, 2, 7, 6, 4};
  cout << equalSumIndex(nums);
  // 3
  return 0;
}
