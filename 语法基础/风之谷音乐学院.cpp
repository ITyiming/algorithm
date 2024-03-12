#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Mod {
    string s; // 模式串
    int n = 0; // 出现次数
};

vector<string> str; // 记录出现次数最多的串

// 计算模式串的出现次数
int countOccurences(string str1, string str2) {
    int l1 = str1.length();
    int l2 = str2.length();
    int n = 0; // 次数
    for (int i = 0; i < l1 - l2 + 1; i++) {
        int k = i;
        int m = 0; // 匹配成功自增标识，m等于l2时匹配成功
        for (int j = 0; j < l2; j++) {
            if (str1[k] == str2[j]) 
                m++;
            k++;
            if (m == l2)
                n++;
        }
    }
    return n;
}

int main() {
    string S;
    cin >> S;
    int n;
    cin >> n;

    Mod M[100]; // 模式串
    for (int i = 0; i < n; i++) {
        cin >> M[i].s;
    }

    // 初始化次数
    for (int j = 0; j < n; j++) {
        M[j].n = countOccurences(S, M[j].s);
    }

    int maxCount = 0;
    for (int j = 0; j < n; j++) {
        maxCount = max(maxCount, M[j].n);
    }

    cout << maxCount << endl;

    // 将符合要求的串填进数组里
    for (int i = 0; i < n; i++) {
        if (M[i].n == maxCount) {
            str.push_back(M[i].s);
        }
    }

    // 按字典序从小到大排序
    sort(str.begin(), str.end());

    // 输出结果
    for (int i = 0; i < str.size(); i++) {
        if (i != str.size() - 1) { // 防越界判断
            if (str[i] != str[i + 1]) // 重复不输出
                cout << str[i] << endl;
        } else {
            cout << str[i];
        }
    }
    return 0;
}
