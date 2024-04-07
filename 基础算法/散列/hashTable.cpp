//
// Created by chenyiming on 2024/4/7.
//
#include <iostream>
#include <vector>

// 定义节点类
class Node {
public:
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

// 定义链式散列表类
class ChainingHashTable {
private:
    int size;
    std::vector<Node*> hash_table;

    // 散列函数，将键转换为散列索引
    int _hash(int key) {
        return key % size;
    }

public:
    ChainingHashTable(int s) : size(s), hash_table(s, nullptr) {}

    // 向散列表中插入键值对
    void insert(int key, int value) {
        int index = _hash(key); // 计算散列索引
        if (hash_table[index] == nullptr) {
            // 若索引位置为空，则直接插入新节点
            hash_table[index] = new Node(key, value);
        } else {
            Node* current = hash_table[index];
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(key, value);
        }
    }

    // 在散列表中查找给定键的值
    int search(int key) {
        int index = _hash(key); // 计算散列索引
        Node* current = hash_table[index];
        while (current) {
            if (current->key == key) {
                return current->value; // 返回键对应的值
            }
            current = current->next;
        }
        return -1; // 键不存在于散列表中
    }
};

int main() {
    ChainingHashTable hash_table(10);

    // 插入键值对
    hash_table.insert(5, 100);
    hash_table.insert(15, 200);
    hash_table.insert(25, 300);

    // 查找键对应的值
    std::cout << "Value for key 5: " << hash_table.search(5) << std::endl; // 输出: 100
    std::cout << "Value for key 15: " << hash_table.search(15) << std::endl; // 输出: 200
    std::cout << "Value for key 25: " << hash_table.search(25) << std::endl; // 输出: 300
    std::cout << "Value for key 10: " << hash_table.search(10) << std::endl; // 输出: -1 (键不存在)

    return 0;
}
