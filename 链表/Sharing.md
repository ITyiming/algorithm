# Sharing

注明：该题目为PAT（程序设计类实验辅助教学平台）Advanced Level Practice 上1032 Sharing 题目

可在这个网址[[Sharing](https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805460652113920?type=7&page=0)]进行评测

---

## **题目：**

给定两个单链表，找出它们的共同后缀的起始位置。

如果两个链表没有共同的后缀，则输出-1。

链表中的节点地址是一个5位的正整数，-1 表示 NULL。

链表中的节点数据是从 {a-z, A-Z} 中选出的英文字母。

---

### **输入格式：**

每个输入文件包含一个测试用例。

对于每个测试用例，第一行包含两个节点地址和一个正整数 N，其中两个地址分别是两个单链表的第一个节点的地址，N 是节点总数。

接下来 N 行，每行描述一个节点，格式为：Address Data Next。

其中 Address 是节点的位置，Data 是节点包含的字母，Next 是下一个节点的位置。

---

### **输出格式：**

对于每个测试用例，输出共同后缀的起始位置，如果两个单链表没有共同的后缀，则输出-1。

---

**示例输入1：**

```
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
```

**示例输出1：**

```
67890
```

---

**示例输入2：**

```
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
```

**示例输出2：**

```
-1
```

---

## 题解

```cpp
#include <iostream>
#include <cstring>
#include <iomanip> // 包含头文件以使用 setw 和 setfill
using namespace std;

const int maxn = 100010;
struct NODE {
    char data;
    int next;
    bool flag;
} node[maxn];

int main() {
    int head1, head2, n;
    cin >> head1 >> head2 >> n;

    // 读取链表节点信息并存储到数组中
    for (int i = 0; i < n; i++) {
        int address, next;
        char data;
        cin >> address >> data >> next;
        node[address].data = data;
        node[address].next = next;
        node[address].flag = false; // 初始化标记为 false
    }

    int p;
    // 遍历链表1，标记链表1中出现的节点
    for (p = head1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }

    // 遍历链表2，找到共同后缀的起始位置
    for (p = head2; p != -1; p = node[p].next) {
        if (node[p].flag) // 如果节点在链表1中已经被标记，则为共同后缀的起始位置
            break;
    }

    // 输出结果
    if (p != -1) {
        // 输出共同后缀的起始位置，setw(5) 设置输出宽度为5，setfill('0') 设置填充字符为 '0'
        cout << setw(5) << setfill('0') << p << endl;
    } else {
        cout << -1 << endl; // 没有找到共同后缀
    }

    return 0;
}
```

注释中详细解释了 `setw` 和 `setfill` 的用法：

- `setw(5)`: 设置输出宽度为5，即输出的字符数为5。如果实际字符数不够5位，则在前面用填充字符填充。
- `setfill('0')`: 设置填充字符为 '0'，即如果实际字符数不够5位，则在前面用 '0' 填充。