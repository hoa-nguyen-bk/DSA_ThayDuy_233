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
    vector<int> spans(n, 1);  // Khởi tạo tất cả spans bằng 1
    stack<int> st;  // Stack để lưu trữ chỉ số
    
    for (int i = 0; i < n; i++) {
        // Loại bỏ các phần tử từ stack khi stack không rỗng và giá trị tại đỉnh
        // stack nhỏ hơn hoặc bằng ns[i]
        while (!st.empty() && ns[st.top()] <= ns[i]) {
            st.pop();
        }
        
        // Nếu stack rỗng, thì ns[i] lớn hơn tất cả các phần tử
        // bên trái nó. Ngược lại, ns[i] lớn hơn các phần tử sau đỉnh stack
        if(st.empty()){
            spans[i] = i+1;
        } else{
            spans[i] = i-st.top();
        }
        
        // Đẩy chỉ số của phần tử này vào stack
        st.push(i);
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