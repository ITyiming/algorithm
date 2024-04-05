//
// Created by chenyiming on 2024/4/5.
//
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 10010;
int n, k, s, A[maxn];  // n个数，选取k个数，使其和为s
vector<int> ans, temp;  // 存放最终结果和当前正在考虑的组合
int maxSumSqu;  // 存放平方和最大值

// 深度优先搜索函数
// index: 当前考虑的数的下标
// nowK: 当前已选取的数的个数
// sumS: 当前已选取的数的和
// sumSqu: 当前已选取的数的平方和
void DFS(int index, int nowK, int sumS, int sumSqu){
    // 若当前已选取的数的和为s，且已选取的数的个数为k，则判断当前组合是否更优
    if(sumS == s && nowK == k){
        if(sumSqu > maxSumSqu){  // 如果平方和更大，则更新结果
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    // 如果已选取的数的个数超过了k，或者当前已选取的数的和超过了s，或者已经考虑完所有数，则返回
    if(nowK > k || sumS > s || index == n) return;
    // 将当前数加入到当前组合中，继续递归搜索
    temp.push_back(A[index]);
    DFS(index + 1, nowK + 1, sumS + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();  // 回溯，将当前数移出当前组合，继续搜索下一个数
    DFS(index + 1, nowK, sumS, sumSqu);  // 不选择当前数，继续搜索下一个数
}

int main(){
    cin >> n >> k >> s;  // 输入n、k、s
    maxSumSqu = 0;  // 初始化平方和最大值为0
    for(int i = 0; i < n; i++) cin >> A[i];  // 输入n个数
    DFS(0, 0, 0, 0);  // 调用DFS函数，从第0个数开始考虑，已选取的数的个数为0，已选取的数的和为0，已选取的数的平方和为0
    // 输出结果
    for(int j = 0; j < ans.size(); j++){
        cout << ans[j] << " ";
    }
    cout << endl;
    cout << maxSumSqu << endl;
    return 0;
}
