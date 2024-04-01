/* mbinary
#########################################################################
# File : polynomial.cpp
# Author: mbinary
# Mail: zhuheqin1@gmail.com
# Blog: https://mbinary.xyz
# Github: https://github.com/mbinary
# Created Time: 2018-05-19  23:07
# Description: 多项式操作程序
#########################################################################
*/

#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<malloc.h>
#include<map>
using namespace std;

#if defined(__linux__)
#define LINUX true
#elif defined(_WIN32)
#define LINUX false
#endif

// 判断一个浮点数是否接近于零
bool  isZero(double a)
{
    if ((a < 0.00001) && -a < 0.00001)
        return true;

    return false;
}

// 多项式类的节点定义
class node
{
    friend class polynomial;
    double coefficient; // 系数
    double index; // 指数
};

// 多项式类的定义
class polynomial
{
    int SIZE; // 存储空间大小
    int n; // 多项式的项数
    node* p; // 存储多项式的节点数组
public:
    polynomial(int sz = 50); // 构造函数
    polynomial(const polynomial &); // 复制构造函数
    ~polynomial(); // 析构函数
    double cal(double); // 计算给定x值下多项式的值
    void getData(); // 从用户输入获取多项式数据
    void display(); // 显示多项式
    polynomial operator=(const polynomial &); // 赋值运算符重载
    polynomial  operator+(const polynomial &); // 加法运算符重载
    polynomial  operator-(const polynomial &); // 减法运算符重载
    polynomial  operator*(const polynomial &); // 乘法运算符重载
};

// 构造函数的定义
polynomial::polynomial(int sz): n(0), SIZE(sz)
{
    p = (node*) new node[SIZE]; // 分配存储空间
    memset(p, 0, sizeof(p)); // 初始化存储空间
}

// 析构函数的定义
polynomial::~polynomial()
{
    delete p; // 释放存储空间
}

// 计算多项式在给定x值下的值
double polynomial::cal(double x)
{
    double rst = 0;

    for (int i = 0; i < n; ++i) {
        rst += pow(x, p[i].index) * p[i].coefficient; // 计算多项式值
    }

    return rst;
}

// 复制构造函数的定义
polynomial::polynomial(const polynomial &a)
{
    p = (node*) new node[50]; // 分配存储空间
    memset(p, 0, sizeof(p)); // 初始化存储空间
    n = a.n; // 复制项数

    for (int i = 0; i < a.n; ++i) {
        p[i].index = a.p[i].index; // 复制指数
        p[i].coefficient = a.p[i].coefficient; // 复制系数
    }
}

// 赋值运算符重载的定义
polynomial polynomial::operator=(const polynomial& a)
{
    n = a.n; // 复制项数

    for (int i = 0; i < a.n; ++i) {
        p[i].index = a.p[i].index; // 复制指数
        p[i].coefficient = a.p[i].coefficient; // 复制系数
    }

    return *this;
}

// 显示多项式的定义
void polynomial::display()
{
    node * tmp = p;

    if (n == 0) {
        printf("0\n"); // 如果多项式为空，则输出0
        return;
    }

    for (int i = n - 1; i >= 0; --i) {
        double t = tmp[i].coefficient; // 获取系数
        double idx = tmp[i].index; // 获取指数

        if (isZero(idx)) {
            printf("%+g", t); // 如果指数为0，则只输出系数
            continue;
        }

        if (isZero(t - 1)) printf("+"); // 如果系数为1，则输出加号
        else if (isZero(t + 1))printf("-"); // 如果系数为-1，则输出减号
        else printf("%+g", t); // 否则输出系数

        printf("x"); // 输出变量x

        if (!isZero(idx - 1)) printf("^%g", idx); // 如果指数不为1，则输出指数
    }

    printf("\n");
}

// 从用户输入获取多项式数据
void polynomial::getData()
{
    printf("Please input data . \n");
    printf("For every item,Coefficient first .Use space to separate,EOF to end\n");
    map<double, double> mp; // 使用map来临时存储多项式数据
    double idx;
    double coef;

    while (scanf("%lf%lf", &coef, &idx) != EOF) {
        if (isZero(coef)) continue; // 如果系数接近于0，则跳过

        if (mp.count(idx) == 0) {
            mp[idx] = coef; // 如果该指数在map中不存在，则直接插入
        } else {
            mp[idx] += coef; // 否则将系数相加

            if (isZero(mp[idx])) {
                mp.erase(idx); // 如果系数为0，则从map中删除该项
            }
        }
    }

    if (mp.size() > SIZE) {
        SIZE *= 2; // 如果map中的项数超过了存储空间大小，则扩大存储空间
        p = (node*)realloc(p, sizeof(node) * SIZE) ;
    }

    for (map<double, double>::iterator it = mp.begin(); it != mp.end(); ++it) {
        p[n].index = it->first;
        p[n++].coefficient = it->second;
    }
}

// 加法运算符重载的定义
polynomial polynomial::operator+(const polynomial & a)
{
    polynomial rst ; // 结果多项式
    int p1 = 0, p2 = 0, p3 = 0; // 三个指针分别指向当前多项式和被加多项式的节点
    double exp1 = p[p1].index; // 当前多项式的指数
    double exp2 = a.p[p2].index; // 被加多项式的指数

    while (p1 < n && p2 < a.n) {
        while (p1 < n && exp1 < exp2) {
            rst.p[p3].index = exp1;
            rst.p[p3].coefficient = p[p1].coefficient;
            ++p1, ++p3;
            exp1 = p[p1].index;;
        }

        while (p2 < a.n && exp1 > exp2) {
            rst.p[p3].index = exp2;
            rst.p[p3].coefficient = a.p[p2].coefficient;
            ++p2, ++p3;
            exp2 = a.p[p2].index;;
        }

        if (isZero(exp1 - exp2)) {
            double tmp = p[p1].coefficient + a.p[p2].coefficient;

            if (isZero(tmp)) {
                ++p1, ++p2;
            } else {
                rst.p[p3].index = p[p1].index;
                rst.p[p3].coefficient = tmp;
                ++p1, ++p2, ++p3;
            }
        }
    }

    if (p1 == n) {
        while (p2 < a.n) {
            rst.p[p3].index = a.p[p2].index;
            rst.p[p3].coefficient =  a.p[p2].coefficient;
            ++p2, ++p3;
        }
    } else {
        while (p1 < n) {
            rst.p[p3].index = p[p1].index;
            rst.p[p3].coefficient = p[p1].coefficient;
            ++p1, ++p3;
        }
    }

    rst.n = p3;
    return rst;
}

// 减法运算符重载的定义
polynomial polynomial::operator-(const polynomial & a)
{
    polynomial rst(a) ; // 结果多项式为被减多项式的复制品
    int i = 0;

    while (i < rst.n) {
        rst.p[i].coefficient = -rst.p[i].coefficient; // 系数取负号
        ++i;
    }

    return (*this + rst); // 调用加法运算符重载
}

// 乘法运算符重载的定义
polynomial polynomial::operator*(const polynomial & a)
{
    map<double, double> mp; // 使用map来临时存储结果多项式的数据

    for (int i = 0; i < n; ++i) {
        double idx = p[i].index; // 当前多项式的指数
        double coef = p[i].coefficient; // 当前多项式的系数

        for (int j = 0; j < a.n; ++j) {
            double index = idx + a.p[j].index; // 计算新的指数

            if (mp.count(index) == 0) {
                mp[index] = coef * a.p[j].coefficient; // 如果该指数不存在，则直接插入
            } else {
                mp[index] += coef * a.p[j].coefficient; // 否则将系数相加

                if (isZero(mp[index])) {
                    mp.erase(index); // 如果系数为0，则从map中删除该项
                }
            }
        }
    }

    int sz = 50;

    while (mp.size() > sz) {
        sz *= 2;
    }

    polynomial rst(sz); // 创建结果多项式对象

    for (map<double, double>::iterator it = mp.begin(); it != mp.end(); ++it) {
        rst.p[rst.n].index = it->first;
        rst.p[rst.n++].coefficient = it->second;
    }

    return rst;
}

int num = 0;
polynomial  pl[30];

// 显示菜单
void menu()
{
    printf("**********OPERATIONS***********\n");
    printf("*****0.   create          *****\n");
    printf("*****1.   add +           *****\n");
    printf("*****2.   sub -           *****\n");
    printf("*****3.   mul *           *****\n");
    printf("*****4.   display         *****\n");
    printf("*****5.   menu            *****\n");
    printf("*****6.   clear screen    *****\n");
    printf("*****7.   exit            *****\n");
    printf("*****8.   copy            *****\n");
    printf("*****9.   display all     *****\n");
    printf("*****10.  cal val         *****\n");
    printf("**********OPERATIONS***********\n");
}

// 主循环
void loop()
{
    int op;

    while (scanf("%d", &op) != EOF) {
        if (op == 0) {
            pl[num].getData();
            ++num;
            printf("You've created polynomial %d:\n", num);
            pl[num - 1].display();
        } else if (op == 1 || op == 2 || op == 3) {
            if (num < 2) {
                printf("Oops! you've got less two polynomial\nPlease choose another operation\n");
                continue;
            }

            printf("input two nums of the two polynomial to be operated.eg: 1 2\n");
            int t1 = 100, t2 = 100;

            while (1) {
                scanf("%d%d", &t1, &t2);

                if (t1 > num || t2 > num || t1 < 0 || t2 < 0) {
                    printf("wrong num ,please input again\n");
                } else break;
            }

            printf("the rst is:\n");
            t1 -= 1, t2 -= 1;

            if (op == 1) {
                (pl[t1] + pl[t2]).display();
            } else if (op == 2) {
                (pl[t1] - pl[t2]).display();
            } else (pl[t1]*pl[t2]).display();
        } else if (op == 4) {
            printf("input a polynomial's num to display it\n");
            int tmp;
            scanf("%d", &tmp);

            if (tmp > num) {
                printf("wrong num");
            } else {
                printf("info of polynomial %d\n", tmp);
                pl[tmp - 1].display();
            }
        } else if (op == 9) {
            for (int i = 0; i < num; ++i) {
                printf("polynomial %d : ", i + 1);
                pl[i].display();
            }
        } else if (op == 5) {
            menu();
        } else if (op == 6) {
            if (LINUX) system("clear");
            else system("cls");

            menu();
        } else if (op == 10) {
            double x;
            int t;
            printf("choose a polynomial\n");
            scanf("%d", &t);

            if (t > num || t < 0) {
                printf("wrong num\n");
            } else {
                printf("input a value\n");
                scanf("%lf", &x);
                pl[t - 1].display();
                printf("%g\n", pl[t - 1].cal(x));
            }
        } else if (op == 8) {
            if (num == 0) {
                printf("you have'nt any polynomial tp copy\n");
                continue;
            }

            int n = num + 1;

            while (n > num) {
                printf("input the  number of an existing polynomial you want to copy\n");
                scanf("%d", &n);
            }

            (pl[num] = pl[n - 1]);
            printf("You've copyed this polynomial:\n");
            pl[num++].display();
        } else exit(0);

        printf("select an operation\n");
    }
}

int main(void)
{
    menu();
    loop();
    return 0;
}
