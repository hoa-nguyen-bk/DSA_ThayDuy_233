/*    */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//---START---
int sumOfMaxSubarray(vector<int> &nums, int k)
{
  // Khởi tạo biến sum để lưu tổng giá trị lớn nhất của các mảng con
  int sum = 0;

  // Khởi tạo deque G để lưu các chỉ số của các phần tử trong mảng nums
  deque<int> G(k);

  // Xử lý cửa sổ đầu tiên có độ dài k
  int i = 0;
  for (i = 0; i < k; i++)
  {
    // Loại bỏ các phần tử nhỏ hơn hiện tại không cần thiết trong deque
    while (!G.empty() && nums[G.back()] <= nums[i])
      G.pop_back(); // Loại bỏ từ phía sau

    // Thêm phần tử hiện tại vào phía sau của deque
    G.push_back(i);
  }
  cout << "i = " << i << endl;
  // Xử lý phần còn lại của mảng nums
  for (; i < nums.size(); i++)
  {
    // Phần tử ở đầu deque là phần tử lớn nhất của cửa sổ trước
    sum += nums[G.front()];

    // Loại bỏ các phần tử không còn nằm trong cửa sổ hiện tại
    while (!G.empty() && G.front() <= i - k)
      G.pop_front();

    // Loại bỏ các phần tử nhỏ hơn hiện tại không cần thiết trong deque
    while (!G.empty() && nums[G.back()] <= nums[i])
      G.pop_back(); // Loại bỏ từ phía sau

    // Thêm phần tử hiện tại vào phía sau của deque
    G.push_back(i);
  }

  // Thêm giá trị lớn nhất của cửa sổ cuối cùng
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
