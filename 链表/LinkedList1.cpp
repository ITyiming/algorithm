#include<iostream>
#include<stdlib.h>

using namespace std;

// 定义链表结点结构体
struct node {
    int data;
    node* next;
};

// 查找元素，在以head为头节点的链表上计数元素x的个数
int search(node* head, int x) {
    int count = 0; // 计数器
    node* p = head->next; // 从第一个结点开始
    while (p != nullptr) { // 只要没有到链表的末尾
        if (p->data == x) {
            count++; // 当前结点数据域为x，则count++
        }
        p = p->next; // 指针移动到下一个结点
    }
    return count;
}

// 插入元素，将x插入以head为头结点的链表的第pos个位置上
void insert(node* head, int pos, int x) {
    node* p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next; // pos-1是为了到插入位置的前一个结点
    }
    node* q = new node; // 新建结点
    q->data = x; // 新结点的数据域为x
    q->next = p->next; // 新结点的下一个结点指向原先插入位置的结点
    p->next = q; // 前一个位置的系欸但指向新节点
}

// 删除以head为头结点的链表的所有为x的结点
void del(node* head, int x){
    node* p = head->next;
    node* pre = head;
    while(p != nullptr){
        if(p->data == x){
            pre->next = p->next; // 调整前一个结点的指针
            delete(p); // 释放内存
            p = pre->next; // 继续检查下一个结点
        }
        else{
            pre = p; // 更新前驱结点
            p = p->next; // 移动到下一个结点
        }
    }
}

// 创建链表（关键函数）
node* create(int array[]) {
    node *head, *p, *pre;
    head = new node; // 创建头结点
    head->next = nullptr; // 头结点的指针域设为nullptr
    pre = head; // pre记录当前结点的前驱结点

    for (int i = 0; i < 5; i++) {
        p = new node; // 新建结点
        p->data = array[i]; // 将array[i]赋给新建结点作为数据域
        p->next = nullptr; // 新结点的指针域设为nullptr
        pre->next = p; // 把pre的下一个结点设为p
        pre = p; // 更新pre为p，作为下个结点的前驱结点
    }

    return head; // 返回头指针
}

int main() {
    int array[5] = {5, 3, 6, 1, 2};
    node* L = create(array); // 新建链表，返回头指针head赋给L
    L = L->next; // 从第一个结点开始有数据域

    while (L != nullptr) {
        cout << L->data << " ";
        L = L->next;
    }

    return 0;
}
