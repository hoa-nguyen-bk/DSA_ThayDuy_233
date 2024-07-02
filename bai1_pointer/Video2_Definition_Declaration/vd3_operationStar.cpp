#include <iostream>
using namespace std;

int main()
{
  int a = 100;

  cout << a <<endl;
  cout << *&a <<endl;//*(&a)
  cout << *&*&a <<endl; 
  cout << *&*&*&a<<endl;
  return 0;
}
