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
