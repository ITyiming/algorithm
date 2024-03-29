# Vector

`std::vector` 是 C++ 标准库中的一个容器，用于存储动态大小的元素序列。它提供了一个类似于数组的接口，但比数组更灵活，因为它可以在运行时动态增加或减少元素的数量。以下是 `std::vector` 的一些基本用法：

### 包含头文件：

```cpp
#include <vector>
```

### 定义和初始化：

```cpp
// 定义一个整数向量
std::vector<int> vec;

// 定义并初始化一个整数向量
std::vector<int> vec = {1, 2, 3, 4, 5};

// 定义指定大小并初始化为相同值的整数向量
std::vector<int> vec(5, 0); // 包含5个值为0的元素
```

### 访问元素：

```cpp
// 访问元素（使用下标）
int value = vec[0];

// 使用迭代器访问元素
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```

### 插入和删除元素：

```cpp
// 在末尾插入元素
vec.push_back(6);

// 在指定位置插入元素
vec.insert(vec.begin() + 2, 10);

// 删除末尾元素
vec.pop_back();

// 删除指定位置的元素
vec.erase(vec.begin() + 1);

// 清空向量
vec.clear();
```

### 其他常用操作：

```cpp
// 获取向量大小
int size = vec.size();

// 判断向量是否为空
bool isEmpty = vec.empty();

// 获取首尾元素
int firstElement = vec.front();
int lastElement = vec.back();

// 修改指定位置的元素
vec[2] = 20;

// 使用迭代器遍历元素
for (auto it = vec.begin(); it != vec.end(); ++it) {
    *it = *it * 2;
}

// 使用范围-based for 循环遍历元素
for (int& x : vec) {
    x = x * 2;
}
```

