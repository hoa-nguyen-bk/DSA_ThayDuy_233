void add(int element)
{
    
}

void add(int index, int element)
{
    
}

 int removeAt(int index) {
    //kiểm tra index
      if(index < 0 || index >= this->count){
          throw std::out_of_range("Out of range");
      }
      //nếu danh sách còn có 1 thằng
      if(this->count == 1){
          Node* tmp = this->head;
          this->head = this->tail = NULL;
          
          //lấy value ra rùi mới delete
          int value = tmp->data;
          delete tmp;
          count--;
          return value;
      }
      
      if(index ==0){
          Node* tmp = this->head;
          this->head = this->head->next;
          tmp->next = NULL;
          
          int value = tmp->data;
          delete tmp;
          count--;
          return value;
      }
      
      if(index == this->count - 1){
          Node* tmp = this->head;
          for(int i = 0; i < index - 1; i++){
              tmp = tmp->next;
          }
          tmp->next = NULL;
          
          int value = tail->data;
          delete this->tail;
          count--;
          
          this->tail = tmp;
          
          return value;
      }
      
      Node* prev = this->head;
      for(int i = 0;i<index-1;i++){
          prev=prev->next;
      }
      Node* cur = prev->next;
      prev->next = cur->next;
      cur->next = NULL;
      
      int value = cur->data;
      delete cur;
      count--;
      
      return value;
    }

bool removeItem(int element)
{
    return false;
}

int get(int index)
{
    return -1;
}

void set(int index, int element)
{
    
}

int indexOf(int element)
{
    return -1;
}

bool contains(int element)
{
    return false;
}

int size()
{
    return 0;
}

bool empty()
{
    return false;
}

void clear()
{
    
}