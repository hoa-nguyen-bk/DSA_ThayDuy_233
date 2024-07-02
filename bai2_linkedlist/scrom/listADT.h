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
