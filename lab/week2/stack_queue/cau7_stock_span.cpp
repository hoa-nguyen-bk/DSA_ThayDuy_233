/* Bài toán stock span là một bài toán về chủ đề kinh tế tài chính, trong đó ta có thông tin về giá của một cổ phiếu qua từng ngày. Mục tiêu của bài toán là tính span của giá cổ phiếu ở từng ngày.
Span của giá cổ phiếu tại ngày thứ i (ký hiệu là Si) được định nghĩa là số ngày liên tục nhiều nhất liền trước ngày thứ i có giá cổ phiếu thấp hơn, cộng cho 1 (cho chính nó).
Yêu cầu. Viết chương trình tính toán chuỗi span từ chuỗi giá cổ phiếu từ đầu vào.
Input. Các giá trị giá cổ phiếu, cách nhau bởi các ký tự khoảng trắng, được đưa vào standard input.
Output. Các giá trị span, cách nhau bởi một khoảng cách, được xuất ra standard ouput.*/
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;
//---START---
std::vector<int> stock_span(const vector<int> &ns)
{
  int n = ns.size();
  vector<int> spans;
  for (int j = n - 1; j >= 0; j--)
  {
    int count = 0;
    for (int i = j - 1; i >= 0; i--)
    {
      if (ns.at(j) > ns.at(i))
      {
        count++;
      }
      else
      {
        break;
      }
    }
    spans.insert(spans.begin() + 0, 1, count + 1);
  }
  return spans;
}
//---END---

int main() {
    // Test case
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    
    // Calculate spans
    vector<int> spans = stock_span(prices);
    
    // Print input
    cout << "Input: ";
    for (int i = 0; i < prices.size(); i++) {
        cout << prices[i];
        if (i < prices.size() - 1) cout << " ";
    }
    cout << endl;
    
    // Print result
    cout << "Result: ";
    for (int i = 0; i < spans.size(); i++) {
        cout << spans[i];
        if (i < spans.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}