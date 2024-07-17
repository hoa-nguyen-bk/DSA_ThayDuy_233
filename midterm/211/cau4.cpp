#include <iostream>
using namespace std;
class CNode {
public:
    int real, img;
    CNode* next;
    CNode* prev;

    CNode(int r, int i) {
        real = r;
        img = i;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    // Tạo các node
    CNode* node1 = new CNode(15, -1);
    CNode* node2 = new CNode(8, 2);
    CNode* node3 = new CNode(5, -8);
    CNode* node4 = new CNode(6, 3);
    CNode* node5 = new CNode(8, 2);

    // Kết nối các node với nhau
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    // Duyệt và in ra thông tin các node
    CNode* current = node1;
    while (current != nullptr) {
        cout << "real = " << current->real << ", img = " << current->img << endl;
        current = current->next;
    }

    return 0;
}