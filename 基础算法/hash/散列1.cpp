#include<iostream>
using namespace std;
const int maxn = 100010;
bool hashTable[maxn] = {false}; // 使用布尔数组来表示哈希表，初始化为false

int main(){
    int n, m, x;
    cin >> n >> m; // 输入数组大小n和查询次数m

    // 建立哈希表
    for(int i = 0; i < n; i++){
        cin >> x;
        hashTable[x] = true; // 将输入的数作为哈希表的索引，对应位置设为true表示存在该数
    }

    // 查询
    for(int i = 0; i < m; i++){
        cin >> x;
        if(hashTable[x] == true){
            cout << "Yes" << endl; // 如果哈希表中存在该数，则输出Yes
        } else {
            cout << "No" << endl; // 否则输出No
        }
    }

    return 0;
}

