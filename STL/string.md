
如果一台机器只能保存3个有效数字，那么浮点数12300和12358.9将被视为相等，因为它们都被简单地舍入为0.123×10^5。现在，给定机器上的有效数字位数和两个浮点数，你应该告诉它们是否在该机器上被视为相等。

输入格式：
每个输入文件包含一个测试用例，其中给出三个数字N、A和B，其中N (<100)是有效数字位数，A和B是要比较的两个浮点数。每个浮点数都是非负的，不超过10^100，并且其总位数小于100。

输出格式：
对于每个测试用例，如果两个数被视为相等，则在一行中打印YES，然后输出标准形式0.d[1]...d[N]*10^k（除非数为0，否则d[1]>0）；如果它们被视为不相等，则打印NO，并在一行中输出它们的标准形式。所有术语必须用空格分隔，行末不能有额外的空格。

```c++
#include <iostream>
#include <string>

using namespace std;

int n; // 有效数字位数

// 处理字符串，得到有效位数和指数
string deal(string s, int& e) {
    int k = 0;
    while (s.length() > 0 && s[0] == '0') {
        s.erase(s.begin()); // 去掉前导零
    }
    if (s[0] == '.') {
        s.erase(s.begin()); // 去掉小数点
        while (s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            e--; // 每去掉一个0，指数减1
        }
    } else {
        while (k < s.length() && s[k] != '.') {
            k++;
            e++; // 统计整数位数，即指数增加
        }
        if (k < s.length()) {
            s.erase(s.begin() + k); // 删除小数点
        }
    }
    
    if (s.length() == 0) {
        e = 0; // 若s变为空，指数设为0
    }
    
    int num = 0;
    k = 0;
    string res;
    while (num < n) { // 取前n位作为有效位数
        if (k < s.length()) {
            res += s[k++];
        } else {
            res += '0'; // 若不足n位，补0
        }
        num++;    
    }
    return res;
}

int main() {
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2; // 输入有效数字位数和两个浮点数

    int e1 = 0, e2 = 0; // 分别记录 s1 和 s2 的指数
    s3 = deal(s1, e1); // 处理s1，得到有效位数和指数
    s4 = deal(s2, e2); // 处理s2，得到有效位数和指数

    if (s3 == s4 && e1 == e2) { // 主体相同且指数相同则输出YES
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl; // 否则输出NO和两个浮点数的标准形式
    }

    return 0;
}
```

