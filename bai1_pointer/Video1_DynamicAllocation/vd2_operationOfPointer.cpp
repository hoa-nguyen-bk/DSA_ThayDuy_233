#include <iostream>
using namespace std;
struct Point
{
  float x, y, z;
};

int main()
{
  int *p1;
  float *p2;
  Point *p3;

  int num = 10 * 10;

  p1 = new int[num];
  p2 = new float[num];
  p3 = new Point[num];

  //Xử lý cái chi đó với 3 khứa này

  delete[] p1;
  delete[] p2;
  delete[] p3;
}
