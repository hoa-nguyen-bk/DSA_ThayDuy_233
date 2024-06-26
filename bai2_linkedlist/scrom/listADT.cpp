#include <string>

template <class T>
class IList
{
public:
  virtual void add(T element) = 0;
  virtual void add(int index, T element) = 0;
  virtual T removeAt(int index) = 0;
  virtual bool removeItem(T item) = 0;
  virtual bool empty() = 0;
  virtual int size() = 0;
  virtual void clear() = 0;
  virtual T get(int index) = 0;
  virtual void set(int index, T element) = 0;
  virtual int indexOf(T item) = 0;
  virtual bool contains(T item) = 0;
  virtual std::string toString() = 0;
};

class IntArrayList : public IList<int>
{
private:
  int *data;
  int capacity;
  int count;

public:
  IntArrayList();
  virtual ~IntArrayList();
  virtual void add(int element);
  virtual void add(int index, int element);
  virtual int removeAt(int index);
  virtual bool removeItem(int item);
  virtual bool empty();
  virtual int size();
  virtual void clear();
  virtual int get(int index);
  virtual void set(int index, int element);
  virtual int indexOf(int item);
  virtual bool contains(int item);
  virtual std::string toString();
  virtual void dump();

private:
  void checkIndex(int index);
  void ensureCapacity(int capacity);
};

