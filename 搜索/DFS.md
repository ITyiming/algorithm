# DFS

## 题目一

给定n个整数，请从中选择k个数，使得这k个数的和为s，并且要求这k个数的平方和尽可能大。请输出这k个数，并输出它们的平方和。

**解题思路：**

这是一个典型的组合问题，可以通过深度优先搜索来解决。首先，定义一个DFS函数，用于递归地搜索可能的组合。在DFS函数中，需要记录当前已选取的数的个数、当前已选取的数的和以及当前已选取的数的平方和。在搜索的过程中，如果已选取的数的和为s，且已选取的数的个数为k，则判断当前组合的平方和是否更大，如果更大则更新结果。否则，继续递归搜索下一个数。在搜索过程中，需要注意回溯操作，即在不同的分支上尝试不同的选择。

在主函数中，输入n、k、s以及n个数，然后调用DFS函数进行搜索，最后输出结果即可。

```cpp
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
```

## 题目二

**题目：**

有n件物品，每件物品的重量为w[i]，价值为c[i]，现在有一个容量为V的背包，要求选取物品放入背包，使得背包中物品的总价值最大。每种物品只能选取一次。请输出背包中物品的最大总价值。

**解题思路：**

这是一个典型的01背包问题，可以通过深度优先搜索来解决。首先，定义一个DFS函数，用于递归地搜索可能的组合。在DFS函数中，需要记录当前已选取的物品总重量和总价值。在搜索的过程中，对于每一件物品，有两种选择：放入背包或不放入背包。如果放入背包，需要判断放入后总重量是否超过背包容量，如果未超过，则更新总价值，并继续递归搜索下一个物品。如果不放入背包，则直接递归搜索下一个物品。在搜索过程中，需要维护一个变量记录最大总价值。

在主函数中，输入物品数量n和背包容量V，以及每件物品的重量和价值。然后调用DFS函数进行搜索，最后输出背包中物品的最大总价值即可。

```cpp
#include<iostream>
using namespace std;

const int maxN = 30;
int w[maxN], c[maxN]; // w数组存放物品重量，c数组存放物品价值
int n, V, maxValue; // n表示物品数量，V表示背包容量，maxValue表示背包中物品的最大总价值

// 深度优先搜索函数
// index: 当前考虑的物品下标
// sumW: 当前已选取的物品总重量
// sumC: 当前已选取的物品总价值
void DFS(int index, int sumW, int sumC){
    // 如果已考虑完所有物品，则返回
    if(index == n){
        return;
    }
    // 不选择当前物品，继续考虑下一个物品
    DFS(index + 1, sumW, sumC);
    // 如果选择当前物品并且总重量不超过背包容量，则继续递归搜索
    if(sumW + w[index] <= V) {
        // 更新总价值为当前总价值加上当前物品的价值
        if (sumC + c[index] > maxValue)
            maxValue = sumC + c[index];
        // 继续搜索下一个物品，更新已选取的物品总重量和总价值
        DFS(index + 1, sumW + w[index], sumC + c[index]);
    }
}

int main(){
    cin >> n >> V; // 输入物品数量n和背包容量V
    // 输入每件物品的重量和价值
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    maxValue = 0; // 初始化最大总价值为0
    // 调用DFS函数进行搜索
    DFS(0, 0, 0);
    // 输出背包中物品的最大总价值
    cout << maxValue << endl;
    return 0;
}
```

