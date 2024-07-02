#include <iostream>
using namespace std;

int main(){
  int a[5];
  int *p = a;
  cout << a << endl;
  cout << p << endl;

  int id = 2;
  
  a[id] = 100;
  p[id] = 100;

  // hoặc sử dụng cộng địa chỉ và toán tử lấy giá trị tham khảo
  *(a+id) = 100;
  *(p+id) = 100;
  return 0;
}
