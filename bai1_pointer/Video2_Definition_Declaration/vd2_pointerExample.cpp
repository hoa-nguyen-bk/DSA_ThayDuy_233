#include <iostream>
using namespace std;
struct Point
{
  double x, y, z;
};

int main()
{
  int a;
  int *p1;
  int *p2 = 0;
  int *p3 = &a;

  double b;
  double *p4;
  double *p5 = 0;
  double *p6 = &b;

  Point c={1.0,2.0,3.0};
  Point *p8;
  Point *p9=0;
  Point *p10=&c;

  return 0;
}
