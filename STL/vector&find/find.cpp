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
