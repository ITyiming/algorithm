#include<iostream>
using namespace std;

void countSort(int arr[], int len) {
    int max = arr[0];
    // 找出数组中的最大值
    for (int i = 1; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    // 创建计数数组
    int* count = new int[max + 1] {0};

    // 计数每个元素出现的次数
    for (int i = 0; i < len; i++) {
        count[arr[i]]++;
    }

    // 累加计数数组
    for (int j = 1; j <= max; j++) {
        count[j] += count[j - 1];
    }

    // 创建临时数组存放排序结果
    int* output = new int[len];

    // 根据计数数组将元素放入临时数组
    for (int k = len - 1; k >= 0; k--) {
        output[count[arr[k]] - 1] = arr[k];
        count[arr[k]]--;
    }

    // 将排序后的结果复制回原数组
    for (int i = 0; i < len; i++) {
        arr[i] = output[i];
    }

    // 释放动态分配的内存
    delete[] count;
    delete[] output;
}

int main() {
    int arr[] = { 2, 4, 2, 1, 6, 5, 4, 3, 8, 8 };
    int len = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
