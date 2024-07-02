#include <iostream>
using namespace std;
struct Point{float x,y,z;};
int main()
{
  Point *ptr = new Point;
  (*ptr).x = 4.5f;
  (*ptr).y = 4.5f;
  (*ptr).z = 4.5f;

  ptr->x = 3.2f;
  ptr->y = 3.3f;
  ptr->z = 2.3f;

  return 0;
}
