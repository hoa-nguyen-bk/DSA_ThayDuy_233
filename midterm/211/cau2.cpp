#include <iostream>
using namespace std;
//---START---
int foo(int* arr, int n) {
    if (n == 1) return arr[0];
    int maxEle = foo(arr, n - 1);
    return (maxEle > arr[n - 1]) ? maxEle : arr[n - 1];
}
//---END---
int main()
{
  const int size = 5;
  int a[size]={1,2,6,3,4};
  cout<< foo(a,size)<<endl;
  return 0;
}
