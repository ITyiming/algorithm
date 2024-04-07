//
// Created by chenyiming on 2024/4/7.
//
#include <vector>
#include <iostream>

class LinearProbeHashTable {
private:
    int size; // 散列表的大小
    int threshold; // 装填因子阈值
    int count; // 当前散列表中的元素个数
    std::vector<std::pair<int, int>> hash_table; // 散列表，存储键值对的向量

    // 散列函数，将键转换为散列索引
    int _hash(int key) {
        return key % size;
    }

    // 获取下一个索引位置，使用线性探测法
    int _next_index(int index) {
        return (index + 1) % size;
    }

    // 重新开辟地址空间，扩大散列表的大小并重新插入已有的键值对
    void resize() {
        size *= 2; // 扩大散列表的大小为原来的两倍
        threshold = size * 0.5; // 更新装填因子阈值
        std::vector<std::pair<int, int>> old_table = hash_table;
        hash_table = std::vector<std::pair<int, int>>(size, std::make_pair(-1, -1));
        count = 0;
        // 重新插入已有的键值对
        for (auto& item : old_table) {
            if (item.first != -1) {
                insert(item.first, item.second);
            }
        }
    }

public:
    // 构造函数，初始化散列表大小和阈值，以及散列表本身
    LinearProbeHashTable(int s) : size(s), threshold(s * 0.7), count(0), hash_table(s, std::make_pair(-1, -1)) {}

    // 向散列表中插入键值对
    void insert(int key, int value) {
        if (count >= threshold) {
            resize(); // 装填因子超过阈值，重新开辟地址空间
        }
        int index = _hash(key); // 计算初始索引
        // 线性探测，直到找到空闲位置插入
        while (hash_table[index].first != -1) {
            index = _next_index(index); // 冲突发生，获取下一个索引位
        }
        hash_table[index] = std::make_pair(key, value); // 插入键值对
        count++;
    }

    // 在散列表中查找给定键的值
    int search(int key) {
        int index = _hash(key); // 计算初始索引
        // 线性探测，直到找到匹配的键或者遇到空位置
        while (hash_table[index].first != -1) {
            if (hash_table[index].first == key) {
                return hash_table[index].second; // 返回键对应的值
            }
            index = _next_index(index); // 冲突发生，获取下一个索引位置
        }
        return -1; // 键不存在于散列表中
    }
};

int main() {
    LinearProbeHashTable hash_table(10);

    // 向散列表中插入键值对
    hash_table.insert(5, 100);
    hash_table.insert(15, 200);
    hash_table.insert(25, 300);

    // 查找键对应的值
    std::cout << "Value for key 5: " << hash_table.search(5) << std::endl;  // 输出: 100
    std::cout << "Value for key 15: " << hash_table.search(15) << std::endl;  // 输出: 200
    std::cout << "Value for key 25: " << hash_table.search(25) << std::endl;  // 输出: 300
    std::cout << "Value for key 10: " << hash_table.search(10) << std::endl;  // 输出: -1 (键不存在)

    return 0;
}
