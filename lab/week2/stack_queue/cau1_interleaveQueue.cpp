/* Cho 1 hàng đợi có số lượng phần tử là số chẵn, sắp xếp lại các phần tử theo quy tắc xen kẽ phần tử ở nửa đầu và nửa sau của hàng đợi.*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//---START---
void interleaveQueue(queue<int> &q)
{
  if (q.empty())
    return;

  int halfSize = q.size() / 2;
  stack<int> s;

  // Step 1: Move the first half of the queue into the stack
  for (int i = 0; i < halfSize; i++)
  {
    s.push(q.front());
    q.pop();
  }

  // Step 2: Enqueue back the stack contents to the queue
  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
  }

  // Step 3: Move the first half of the queue to the back of the queue
  for (int i = 0; i < halfSize; i++)
  {
    q.push(q.front());
    q.pop();
  }

  // Step 4: Move the first half of the queue into the stack again
  for (int i = 0; i < halfSize; i++)
  {
    s.push(q.front());
    q.pop();
  }

  // Step 5: Interleave the elements of the stack and the queue
  while (!s.empty())
  {
    q.push(s.top());
    s.pop();
    q.push(q.front());
    q.pop();
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
