#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//const int N = 1e5 + 3;  // 定义常量N表示最大水阀数量
int n, m;
vector<pair<int, int>> w;

bool check(int mid){
    vector<pair<int, int>> p; // 存储水阀有效影响区间的临时数组
    for(vector<pair<int, int>>::iterator it = w.begin(); it != w.end(); it++){ // 遍历水阀数组
        int L = it -> first; // 获取当前水阀的位置
        int S = it -> second; // 获取当前水阀的开启时间
        if(mid >= S){ // 如果当前时刻大于等于水阀的开启时间
            int t = mid - S; // 计算水流到达当前水阀的时间差
            int l = max(1, L - t), r = min(m, L + t); // 计算当前水阀的有效影响区间
            p.push_back({l, r}); // 将有效影响区间存入临时数组p中
        }
    }
    sort(p.begin(), p.end()); // 对临时数组p按照左端点升序排序
    int st = -1, ed = -1; // 初始化起点和终点
    for(vector<pair<int, int>>::iterator it = p.begin(); it != p.end(); it++){ // 遍历排序后的临时数组p
        int l = it -> first; // 获取当前区间的左端点
        int r = it -> second; // 获取当前区间的右端点
        if(l <= ed + 1) ed = max(ed, r); // 如果当前区间的左端点小于等于前一个区间的右端点+1，更新终点
        else st = l, ed = r; // 否则更新起点和终点
    }
    return st == 1 && ed >= m; // 返回有效区间是否覆盖了整个管道
}

int main(){
    cin >> n >> m; // 读取水阀数量和管道长度
    int L, S;
    for(int i = 0; i < n; i++){
        cin >> L >> S; // 读取每个水阀的位置和开启时间
        w.push_back({L, S}); // 将水阀位置和开启时间存入数组w中
    }
    int l = 0;
    int r = 2e9 ; // 初始化二分查找的左右边界
    while(l < r){ // 进行二分查找
        int mid = l + (r - l) / 2; // 计算中间时刻
        if(check(mid)) r = mid; // 如果mid满足条件，则更新右边界
        else l = mid + 1; // 否则更新左边界
    }
    cout << r << endl; // 输出结果
    return 0;
}