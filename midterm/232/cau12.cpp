#include <iostream>
using namespace std;
//---START---
void func(int number)
{
  if (number <= 0)
    return;
  else
  {
    func(number / 2);
    cout << number % 2;
  }
}

//---END---
int main()
{
  func(301);
  return 0;
}
