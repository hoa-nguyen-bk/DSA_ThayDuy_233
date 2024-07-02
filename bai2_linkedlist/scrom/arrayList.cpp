#include "listADT.h"

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

IntArrayList::IntArrayList()
{
  this->capacity = 10;
  this->data = new int[this->capacity];
  this->count = 0;
}

IntArrayList::~IntArrayList()
{
  delete[] this->data;
}

void IntArrayList::add(int element)
{
  this->ensureCapacity(this->count + 1);
  this->data[this->count] = element;
  this->count++;
}

void IntArrayList::add(int index, int element)
{
  this->checkIndex(index);               // kiểm tra xem index này có tồn tại trong mảng ko
  this->ensureCapacity(this->count + 1); // kiểm tra mảng có đủ sức chứa hay ko

  int moveCount = this->count - index; // tính ra số lượng p tử cần phải dịch
  if (moveCount > 0)
  {
    // memmove chứa 3 thành phần:
    // 1. địa chỉ nơi mà thành phần định move tới: tức đích đến + 1 đơn vị
    // 2. nơi để ta lấy dịch: là vị trí hiện tại
    // 3. số lượng ptu cần dịch nhân cho kích thước 1 phần tử
    memmove(this->data + index + 1,
            this->data + index,
            moveCount * sizeof(int));
    
  }
}