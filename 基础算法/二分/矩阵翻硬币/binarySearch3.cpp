#include<iostream>
#include<algorithm>
using namespace std;

string multi(string s1, string s2){ // 大数乘法
    int num[500] = {0};
    string ans;
    for(int i = 0; i < s1.length(); i++){ // 计算并存储到num中
        for(int j = 0; j < s2.length(); j++){
            num[i + j + 1] += (s1[i] - '0')*(s2[j] - '0');  
        }
    }
    int count = s1.length() + s2.length() - 1;
    for(int n = count; n >= 1; n--){ // num数组处理
        if(num[n] > 9){
            num[n - 1] += num[n] / 10;
            num[n] = num[n] % 10;
        }
    }
    for (int t = 0; t <= count; t++){ // 将num数组存到ans字符串中，注意进位为0的情况
        if (!t && num[t] || t)
            ans.push_back(num[t] + '0');
    }
    return ans;
}

bool strcmp(string s1, string s2, int pos){ // 比较两字符串大小，pos代表应该在s1后面填几个零
    if(s1.length() + pos != s2.length()) // 如果s1位数不等于s2
        return s1.length() + pos > s2.length();
    else  // 位数相等
        return s1 > s2;
}

string square(string s)// 大数平方根取整
{
    int len;
    string ans;
    if(s.length() % 2 == 0) // 长度为偶数
        len = s.length() / 2;
    else len = s.length() / 2 + 1;
    for(int i = 0; i < len; i++){ // 一位一位的循环
        ans.push_back('0');
        for(int j = 0; j <= 9; j++){
            if(strcmp(multi(ans, ans), s, 2*(len - 1 - i))) // 需要添加0的个数是2 * (len - 1 - i)
                break;
                break;
            ans[i]++;
        }
        ans[i]--;
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << multi(square(s1), square(s2)) << endl;
    return 0;
}
