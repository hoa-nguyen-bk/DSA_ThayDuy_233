/*
Given an array of integers.
Your task is to implement a function with the following prototype:
bool consecutiveOnes(vector<int>& nums);
The function returns if all the 1s appear consecutively in nums. If nums does not contain any elements, please return true
*/
#include <iostream>
#include <vector>
using namespace std;
//---START---
bool consecutiveOnes(vector<int>& nums) {
    int len = nums.size();
    bool foundOne = false;  // Đã tìm thấy số 1 chưa
    bool checkingOnes = false;  // Đang kiểm tra chuỗi số 1

    for (int i = 0; i < len; i++) {
        if (nums[i] == 1) {
            if (!foundOne) {
                foundOne = true;
                checkingOnes = true;
            } else if (!checkingOnes) {
                // Nếu tìm thấy số 1 sau khi đã kiểm tra chuỗi số 1 xong
                return false;
            }
        } else {
            if (checkingOnes) {
                checkingOnes = false;
            }
        }
    }

    return true;
}
//---END----
int main()
{
  vector<int> nums{0, 1, 1, 1, 9, 8};
  cout << consecutiveOnes(nums);
  // 1
  return 0;
}
