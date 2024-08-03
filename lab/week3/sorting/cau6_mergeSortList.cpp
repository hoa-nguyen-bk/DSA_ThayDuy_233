#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int _val = 0, ListNode *_next = nullptr) : val(_val), next(_next) {}
};

//---START---
ListNode *mergeLists(ListNode *a, ListNode *b)
{
  if (!a)
    return b;
  if (!b)
    return a;

  ListNode *head = nullptr;
  ListNode *tail = nullptr;
  if (a->val <= b->val)
  {
    head = a;
    a = a->next;
  }
  else
  {
    head = b;
    b = b->next;
  }
  tail = head;

  while (a && b)
  {
    if (a->val <= b->val)
    {
      tail->next = a;
      a = a->next;
    }
    else
    {
      tail->next = b;
      b = b->next;
    }
    tail = tail->next;
  }

  if (a)
    tail->next = a;
  else
    tail->next = b;

  return head;
}

ListNode *mergeSortList(ListNode *head)
{
  if (!head || !head->next)
    return head;

  ListNode *slow = head;
  ListNode *fast = head->next;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode *mid = slow->next;
  slow->next = nullptr;

  ListNode *left = mergeSortList(head);
  ListNode *right = mergeSortList(mid);

  return mergeLists(left, right);
}

//---END---
ListNode *init(int *array, int size, unordered_map<ListNode *, int> &nodeAddr)
  {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;
    for (int i = 0; i < size; i++)
    {
      ListNode *node = new ListNode(array[i]);
      nodeAddr[node] = array[i];
      if (!head)
      {
        head = node;
        curr = node;
      }
      else
      {
        curr->next = node;
        curr = curr->next;
      }
    }
    return head;
  }
void printList(ListNode *head, unordered_map<ListNode *, int> &nodeAddr)
{
  ListNode *curr = head;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  int size;
  cin >> size;
  int *array = new int[size];

  

  for (int i = 0; i < size; i++)
    cin >> array[i];
  unordered_map<ListNode *, int> nodeAddr;
  ListNode *head = init(array, size, nodeAddr);
  ListNode *sorted = mergeSortList(head);
  try
  {
    printList(sorted, nodeAddr);
  }
  catch (char const *err)
  {
    cout << err << '\n';
  }
  deleteList(sorted);
  delete[] array;
  // 9
  // 9 3 8 2 1 6 7 4 5
  // 1 2 3 4 5 6 7 8 9
  return 0;
}
