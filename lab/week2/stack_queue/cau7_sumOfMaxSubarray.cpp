/* The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//---START---
int sumOfMaxSubarray(vector<int> &nums, int k)
{
  int sum = 0;
  deque<int> G(k);
  int i = 0;
  for (i = 0; i < k; i++)
  {
    while ((!G.empty()) && nums[G.back()] <= nums[i])
      G.pop_back();
    G.push_back(i);
  }
  for (; i < nums.size(); i++)
  {
    sum += nums[G.front()];
    while (!G.empty() && G.front() <= i - k)
      G.pop_front();
    while ((!G.empty()) && nums[G.back()] <= nums[i])
      G.pop_back(); // Remove from rear
    G.push_back(i);
  }
  sum += nums[G.front()];
  return sum;
}
//---END---
int main()
{
  vector<int> nums{1, 2, 4, 3, 6};
  int k = 3;
  cout << sumOfMaxSubarray(nums, k);
  // 14

  return 0;
}
