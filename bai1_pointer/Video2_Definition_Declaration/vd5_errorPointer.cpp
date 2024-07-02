#include <iostream>
using namespace std;

int main()
{

  int b = 100;

  const int * ptr1;
  int * ptr3 = &b;

  ptr1 = ptr3;
  ptr3 = ptr1;

  return 0;
}
