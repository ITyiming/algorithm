//
// Created by chenyiming on 2024/4/5.
//
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
