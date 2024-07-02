#include <iostream>
using namespace std;

int main()
{
  int num = 10 * 10;
  int *p1 = new int[num];
 
  if (p1 == NULL)
  {
    cout << "Allocation: Failed" << endl;
    return 1;
  }
  else
  {
    // do something with p1
    delete[] p1;
  }
  return 0;
}
