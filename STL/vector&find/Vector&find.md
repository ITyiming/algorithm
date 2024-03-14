# Vector

`std::vector` 是 C++ 标准库中的容器，它提供了动态数组的功能，并且能够自动管理内存。以下是关于 `std::vector` 常见用法的详细解释：

## 常见用法

1. **包含头文件**：

   首先，你需要包含 `<vector>` 头文件来使用 `std::vector` 容器。

   ```cpp
   #include <vector>
   ```

2. **声明和初始化**：

   你可以使用以下语法来声明和初始化 `std::vector`：

   ```cpp
   std::vector<int> ids; // 声明一个空的 vector，存储 int 类型的数据
   std::vector<int> ids(5); // 声明一个具有 5 个元素的 vector，初始值为默认值
   std::vector<int> ids = {1, 2, 3, 4, 5}; // 声明并初始化一个 vector
   ```

3. **向 vector 中添加元素**：

   你可以使用 `push_back()` 函数向 `std::vector` 中添加元素。

   ```cpp
   ids.push_back(10); // 向 ids 后面添加一个元素，值为 10
   ```

4. **访问 vector 中的元素**：

   你可以使用下标或迭代器来访问 `std::vector` 中的元素。

   ```cpp
   int element = ids[0]; // 获取 ids 中第一个元素的值
   ```

5. **获取 vector 的大小**：

   使用 `size()` 函数可以获取 `std::vector` 中元素的数量。

   ```cpp
   int size = ids.size(); // 获取 ids 中元素的数量
   ```

6. **迭代 vector 中的元素**：

   可以使用范围 for 循环或迭代器来迭代 `std::vector` 中的元素。

   ```cpp
   for (int num : ids) {
       std::cout << num << " ";
   }

   // 或者使用迭代器
   for (std::vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
       std::cout << *it << " ";
   }
   ```

7. **排序 vector**：

   使用标准库提供的排序算法（如 `std::sort()`）可以对 `std::vector` 进行排序。

   ```cpp
   std::sort(ids.begin(), ids.end()); // 对 ids 中的元素进行升序排序
   ```

8. **查找元素**：

   可以使用标准库提供的查找算法（如 `std::find()`）来在 `std::vector` 中查找特定的元素。

   ```cpp
   auto it = std::find(ids.begin(), ids.end(), 5); // 在 ids 中查找值为 5 的元素
   if (it != ids.end()) {
       std::cout << "Element found at position: " << it - ids.begin() << std::endl;
   } else {
       std::cout << "Element not found" << std::endl;
   }
   ```

   **注释：**

   **`auto it = std::find(ids.begin(), ids.end(), 5);`**：

   这里的 `auto` 也是C++11中引入的关键字，用于自动推断变量的类型。在这个语句中，`std::find()` 返回的是一个迭代器，但是我们并不需要显式地指定这个迭代器的类型，而是让编译器自动推断。因此，`auto` 关键字的作用是告诉编译器根据等号右侧的表达式来推断变量 `it` 的类型。

   `ids.begin()` 和 `ids.end()` 是 `std::vector` 提供的成员函数，分别返回一个指向容器起始位置和结束位置的迭代器。`std::find()` 函数用于在指定范围内查找指定值，`ids.begin()` 表示查找的起始位置，`ids.end()` 表示查找的结束位置。这里的 `ids.end()` 表示的是指向容器中**最后一个元素之后的位置**，通常称为“**尾后迭代器**”。使用这个迭代器表示查找的结束位置是一种惯用的写法，确保在查找过程中不会越界。

9. **删除元素**：

   使用 `erase()` 函数可以从 `std::vector` 中删除元素。

   ```cpp
   ids.erase(ids.begin() + 2); // 删除 ids 中索引为 2 的元素
   ```

10. **清空 vector**：

    使用 `clear()` 函数可以清空 `std::vector` 中的所有元素。

    ```cpp
    ids.clear(); // 清空 ids 中的所有元素
    ```

11. **动态调整大小**：

    `std::vector` 可以动态地调整其大小。如果添加的元素数量超过当前大小，`std::vector` 会自动扩展其内部存储空间以容纳更多元素。

12. **内存管理**：

    `std::vector` 会自动管理其内存，当其不再需要时，会自动释放其内存。这样可以避免内存泄漏和手动内存管理的复杂性。

## vector创建二维数组

在C++中，可以使用 `std::vector` 容器来定义二维数组。下面是使用 `std::vector` 定义二维数组的方法：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    // 定义一个二维 vector，每个元素是一个 vector<int>。释：matrix，矩阵
    vector<vector<int>> matrix;
    
    // 初始化二维数组
    int rows = 3;
    int cols = 4;
    for (int i = 0;i < rows;++i){
        vector<int> row; // 定义一行
        for (int j = 0; j < cols; ++j){
            row.push_back(i*cols + j); // 向行添加元素
        }
        matrix.push_back(row); // 将行添加道二维数组中
    }

    // 访问二维数组元素
    for(int i = 0; i < rows; ++i){
        for(int j=0; j < cols; ++j){
            cout << matrix[i][j] << " "; // 输出元素值
        }
        cout << endl;
    }
    return 0;
}
```

上述代码定义了一个 3 行 4 列的二维数组，并进行了初始化。其中 `std::vector<std::vector<int>>` 定义了一个二维 vector，每个元素都是一个 `std::vector<int>`，即代表一行。通过循环将每一行添加到二维数组中，然后通过两层循环访问二维数组中的每个元素。

# find

`std::find()` 函数是C++标准库 `<algorithm>` 头文件中提供的一个函数，用于在指定范围内查找特定值的元素。以下是关于 `std::find()` 函数的详细介绍：

1. **函数原型**：

   ```cpp
   template< class InputIt, class T >
   InputIt find( InputIt first, InputIt last, const T& value );
   ```

   - `InputIt first`：指定范围的起始位置（包含）。
   - `InputIt last`：指定范围的结束位置（不包含）。
   - `const T& value`：要查找的值。

   `std::find()` 返回一个迭代器，指向第一个等于指定值的元素。如果找不到匹配的元素，则返回 `last`。

2. **使用方法**：

   ```cpp
   auto it = std::find(ids.begin(), ids.end(), value);
   ```

   这里的 `ids` 是容器（例如 `std::vector`）的对象，`value` 是要查找的值。`std::find()` 函数将在 `ids` 容器中从 `begin()` 到 `end()` 范围内查找值为 `value` 的元素。

   如果找到了指定值的元素，则返回指向该元素的迭代器；如果未找到，则返回 `ids.end()`，表示找不到匹配的元素。

3. **示例**：

   ```cpp
   std::vector<int> numbers = {1, 2, 3, 4, 5};
   int value = 3;
   auto it = std::find(numbers.begin(), numbers.end(), value);
   if (it != numbers.end()) {
       std::cout << "Value " << value << " found at index " << it - numbers.begin() << std::endl;
   } else {
       std::cout << "Value " << value << " not found" << std::endl;
   }
   ```

   这个示例中，我们在 `numbers` 容器中查找值为 `value` 的元素。如果找到了该元素，我们打印出它的索引；如果未找到，则打印出未找到的消息。

4. **注意事项**：

   - `std::find()` 可以用于各种容器，如 `std::vector`、`std::list`、`std::array` 等。
   - 对于无序容器（如 `std::unordered_set`、`std::unordered_map`），`std::find()` 也可以用于查找元素，但是它的性能可能不如有序容器。
   - 如果要查找的值是自定义类型，需要定义比较操作符（`operator==`）或提供自定义的比较函数。
   - `std::find()` 函数的时间复杂度为线性，即 O(n)，其中 n 是查找范围内的元素数量。

### 代码示例

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // 创建一个存储整数的 vector
    vector<int> numbers = {1, 2, 3, 4, 5};

    // 要查找的值
    int value = 3;

    // 在 numbers 容器中查找值为 value 的元素
    auto it = find(numbers.begin(), numbers.end(), value);

    // 如果找到了值为 value 的元素
    if (it != numbers.end()) {
        // 输出找到的值及其索引位置
        cout << "Value " << value << " found at index " << it - numbers.begin() << endl;
    } 
    else {
        // 如果未找到值为 value 的元素
        cout << "Value " << value << " not found" << endl;
    }

    return 0;
}

```

