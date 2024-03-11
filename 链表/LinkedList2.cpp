#include <iostream>

// 链表节点
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 链表类
class LinkedList {
private:
    Node* head; // 头节点指针
public:
    LinkedList() : head(nullptr) {}
    
    // 插入操作，在链表末尾插入新节点
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    
    // 删除操作，删除指定值的节点
    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) {
            curr = curr->next;
        }
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
    
    // 遍历操作，打印链表中的所有节点值
    void traverse() {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.traverse(); // 输出：1 2 3
    
    list.remove(2);
    list.traverse(); // 输出：1 3
    
    return 0;
}