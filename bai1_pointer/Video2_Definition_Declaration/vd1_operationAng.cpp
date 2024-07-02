#include <iostream>
using namespace std;
struct Point
{
  double x, y, z;
};

int main()
{
  int a = 5;
  cout << a << endl;
  cout << &a << endl;

  Point p1 = {1.0, 2.0, 3.0};
  cout << p1.x << endl;
  cout << &p1 << " " << &p1.x << endl;
  cout << &p1.y << " " << &p1.z << endl;

  return 0;
}
