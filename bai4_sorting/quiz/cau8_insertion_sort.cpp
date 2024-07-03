
#include <iostream>

using namespace std;

template <class T>
class ISort
{
public:
  virtual ~ISort() {};
  virtual void sort(T array[], int size, int (*comparator)(T &, T &) = 0) = 0;
};

template <class T>
class SortSimpleOrder
{
public:
  static int compare4Ascending(T &lhs, T &rhs)
  {
    if (lhs < rhs)
      return -1;
    else if (lhs > rhs)
      return +1;
    else
      return 0;
  }
  static int compare4Desending(T &lhs, T &rhs)
  {
    if (lhs < rhs)
      return +1;
    else if (lhs > rhs)
      return -1;
    else
      return 0;
  }
};

template <class T>
class StraightInsertionSort : public ISort<T>
{
public:
  void sort(T array[], int size, int (*comparator)(T &, T &))
  {
    int current;
    int walker;
    T temp;
    current = 1;
    while (current < size)
    {
      temp = array[current];
      walker = current - 1;
      while ((walker >= 0) && comparator(temp, array[walker]) < 0)
      {
        array[walker + 1] = array[walker]; // shift to right
        walker -= 1;
      }
      array[walker + 1] = temp;
      current += 1;
      cout << "\nin ra thử xem sao: ";
      for (int i = 0; i < size; i++)
      {
        cout << array[i] << " ";
      }
      cout << endl;
    }
  }
};
int main()
{
  int array[] = {4, 3, 2, 10, 12, 1, 5, 6};
  int size = sizeof(array) / sizeof(array[0]);

  // Create an instance of StraightInsertionSort
  StraightInsertionSort<int> insertionSort;

  // Sort the array in ascending order
  insertionSort.sort(array, size, SortSimpleOrder<int>::compare4Ascending);

  // Print the sorted array
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;

  return 0;
}