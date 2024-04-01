#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;

struct node{
    double num; //操作数
    char op; // 操作符
    bool flag; // true表示操作数，false表示操作符
};

string str;
stack<node> s; // 操作符栈
queue<node> q; // 后缀表达式序列
map<char, int> op; // 操作符运算优先级

void Change(){ // 将中缀表达式转换为后缀表达式
    double num;
    node temp;
    for(int i = 0; i < str.length();){
        if(str[i] >= '0'&& str[i] <= '9'){ // 如果是数字
            temp.flag = true; // 标记为数字
            temp.num = str[i++] - '0'; //记录这个操作数的每一个数位
            while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
                temp.num = temp.num * 10 + (str[i] - '0'); // 更新这个操作数
                i++;
            }
            q.push(temp); // 将这个操作数压入后缀表达式的队列
        } else { // 如果是操作符
            temp.flag = false; // 标记为操作符
            // 只要操作符栈的栈顶元素闭该操作符的优先级高
            // 就把操作符栈栈顶元素弹出到后缀表达式的队列中
            while(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp); // 将操作符压入操作符栈中
            i++;
        }
    }
    // 如果操作符栈中还有操作符，就把它弹出到后缀表达式队列中
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

double Cal(){ // 计算后缀表达式
    double temp1, temp2;
    node cur, temp;
    while(!q.empty()){ // 只要后缀表达式队列非空
        cur = q.front(); // cur记录队首元素
        q.pop();
        if(cur.flag == true) s.push(cur); // 如果是操作数直接压入栈
        else { // 如果是操作符
            temp2 = s.top().num; // 弹出第二操作数；
            s.pop();
            temp1 = s.top().num; // 弹出第一操作数；
            s.pop();
            temp.flag = true; // 临时记录操作数
            if(cur.op == '+') temp.num = temp1 + temp2; // 加法
            else if(cur.op == '-') temp.num = temp1 - temp2; // 减法
            else if(cur.op == '*') temp.num = temp1 * temp2; // 乘法
            else temp.num = temp1 / temp2; // 除法
            s.push(temp);
        }
    }
    return s.top().num; // 栈顶元素是后缀表达式的值
}

int main(){
    op['+'] = op['-'] = 1; // 设定操作符优先级
    op['*'] = op['/'] = 2;
    while(getline(cin, str), str != "0"){
        for(string::iterator it = str.end(); it != str.begin(); it--){
            if(*it == ' ') str.erase(it); // 把表达式中的空格全部去掉
        }
        while(!s.empty()) s.pop(); //初始化栈
        Change(); // 将中缀表达式转换为后缀表达式
        printf("%.2f\n", Cal()); // 计算后缀表达式
    }
    return 0;
}