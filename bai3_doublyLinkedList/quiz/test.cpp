#include <iostream>
#include <stdexcept>

class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    // Thêm phần tử vào cuối danh sách
    void add(int element) {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // Thêm phần tử vào vị trí có chỉ số index
    void add(int index, int element) {
        if (index < 0 || index > count) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            Node* newNode = new Node(element);
            newNode->next = head;
            head = newNode;
            if (count == 0) {
                tail = newNode;
            }
        } else {
            Node* prev = getNode(index - 1);
            Node* newNode = new Node(element);
            newNode->next = prev->next;
            prev->next = newNode;
            if (index == count) {
                tail = newNode;
            }
        }
        count++;
    }

    // Lấy giá trị của phần tử có chỉ số index
    int get(int index) {
        Node* node = getNode(index);
        return node->data;
    }

    // Thiết lập giá trị cho phần tử có chỉ số index
    void set(int index, int element) {
        Node* node = getNode(index);
        node->data = element;
    }

    // Trả về chỉ số của phần tử element, nếu không tìm thấy trả về -1
    int indexOf(int element) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == element) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    // Kiểm tra xem danh sách có chứa phần tử element không
    bool contains(int element) {
        return indexOf(element) != -1;
    }

    // Xóa phần tử tại vị trí có chỉ số index
    int removeAt(int index) {
        // TODO: Implement this method
        return 0;
    }

    // Xóa phần tử có giá trị item
    bool removeItem(int item) {
        // TODO: Implement this method
        return false;
    }

    // Kiểm tra danh sách có rỗng không
    bool empty() {
        return count == 0;
    }

    // Trả về số lượng phần tử trong danh sách
    int size() {
        return count;
    }

private:
    // Lấy node tại vị trí có chỉ số index
    Node* getNode(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }

public:
    class Node {
    public:
        int data;
        Node* next;

        Node() : next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
    };
};

int main() {
    IntSLinkedList list;
    int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    for (int idx = 0; idx < 8; idx++) {
        list.add(index[idx], values[idx]);
    }

    std::cout << list.get(2) << std::endl;

    try {
        std::cout << list.get(11);
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range";
    }

    return 0;
}
