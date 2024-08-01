/* Cho 1 hàng đợi có số lượng phần tử là số chẵn, sắp xếp lại các phần tử theo quy tắc xen kẽ phần tử ở nửa đầu và nửa sau của hàng đợi.*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//---START---
void interleaveQueue(queue<int> &hangDoi)
{
  if (hangDoi.empty())
    return;
  int halfSize = hangDoi.size() / 2;
  stack<int> nganXep;
  for (int i = 0; i < halfSize; i++)
  {
    nganXep.push(hangDoi.front());
    hangDoi.pop();
  }
  while (!nganXep.empty())
  {
    hangDoi.push(nganXep.top());
    nganXep.pop();
  }
  for (int i = 0; i < halfSize; i++)
  {
    hangDoi.push(hangDoi.front());
    hangDoi.pop();
  }
  for (int i = 0; i < halfSize; i++)
  {
    nganXep.push(hangDoi.front());
    hangDoi.pop();
  }
  while (!nganXep.empty())
  {
    hangDoi.push(nganXep.top());
    nganXep.pop();
    hangDoi.push(hangDoi.front());
    hangDoi.pop();
  }
}

//---END---
int main()
{
  queue<int> q;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int element;
    cin >> element;
    q.push(element);
  }
  interleaveQueue(q);
  while (!q.empty())
  {
    cout << q.front() << ' ';
    q.pop();
  }
  return 0;
}
