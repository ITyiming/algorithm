#include<iostream>
using namespace std;
const int maxn = 100010;
bool hashTable[maxn] = {false}; // ʹ�ò�����������ʾ��ϣ����ʼ��Ϊfalse

int main(){
    int n, m, x;
    cin >> n >> m; // ���������Сn�Ͳ�ѯ����m

    // ������ϣ��
    for(int i = 0; i < n; i++){
        cin >> x;
        hashTable[x] = true; // �����������Ϊ��ϣ�����������Ӧλ����Ϊtrue��ʾ���ڸ���
    }

    // ��ѯ
    for(int i = 0; i < m; i++){
        cin >> x;
        if(hashTable[x] == true){
            cout << "Yes" << endl; // �����ϣ���д��ڸ����������Yes
        } else {
            cout << "No" << endl; // �������No
        }
    }

    return 0;
}

