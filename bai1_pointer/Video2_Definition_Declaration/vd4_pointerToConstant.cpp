#include <iostream>
using namespace std;

int main()
{
  int a = 20;
  int b = 30;
  int c = 40;

  //pointer to constant
  const int *p1 = &a;
  int const *p2 = &a;

  //constant pointer
  int* const p3 = &a;

  return 0;
}
