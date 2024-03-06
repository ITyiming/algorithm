#include<iostream>
using namespace std;

void countSort(int arr[], int len) {
    int max = arr[0];
    // �ҳ������е����ֵ
    for (int i = 1; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    // ������������
    int* count = new int[max + 1] {0};

    // ����ÿ��Ԫ�س��ֵĴ���
    for (int i = 0; i < len; i++) {
        count[arr[i]]++;
    }

    // �ۼӼ�������
    for (int j = 1; j <= max; j++) {
        count[j] += count[j - 1];
    }

    // ������ʱ������������
    int* output = new int[len];

    // ���ݼ������齫Ԫ�ط�����ʱ����
    for (int k = len - 1; k >= 0; k--) {
        output[count[arr[k]] - 1] = arr[k];
        count[arr[k]]--;
    }

    // �������Ľ�����ƻ�ԭ����
    for (int i = 0; i < len; i++) {
        arr[i] = output[i];
    }

    // �ͷŶ�̬������ڴ�
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
