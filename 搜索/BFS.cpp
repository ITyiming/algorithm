//
// Created by chenyiming on 2024/4/5.
//
#include<iostream>
#include<queue>
using namespace std;

// 定义结构体表示节点的坐标
struct node{
    int x;
    int y;
}Node;

const int maxn = 10010;
int matrix[maxn][maxn]; // 原始矩阵
int m, n; // 矩阵的行数和列数
bool log[maxn][maxn] = {false}; // 记录某个位置是否被访问过的标记数组
int X[4] = {0, 0, 1, -1}; // 方向数组，用于探索上下左右四个方向
int Y[4] = {1, -1, 0, 0 };

// 判断某个位置是否合法，即是否在矩阵范围内且未被访问过且为1
bool judge(int x, int y){
    if(x < 0 || x >= m || y < 0 || y >= n) // 越界判断
        return false;
    if(log[x][y] == true || matrix[x][y] == 0) // 已访问或者为0的位置不合法
        return false;
    return true;
}

// BFS遍历连通块
void BFS(int x, int y){
    queue<node> Q; // 定义队列存放待访问的节点
    Node.x = x;
    Node.y = y;
    Q.push(Node); // 将起始节点加入队列
    node top;
    int nowX, nowY;
    while(!Q.empty()){ // 当队列非空时循环
        top = Q.front(); // 取出队首节点
        Q.pop(); // 弹出队首节点
        for(int i = 0; i < 4; i++){ // 遍历上下左右四个方向
            nowX = top.x + X[i];
            nowY = top.y + Y[i];
            if(judge(nowX, nowY)){ // 判断新位置是否合法
                Node.x = nowX;
                Node.y = nowY;
                Q.push(Node); // 将新位置加入队列
                log[nowX][nowY] = true; // 标记为已访问
            }
        }
    }
}

int main(){
    cin >> m >> n; // 输入矩阵的行数和列数
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j]; // 输入矩阵的元素值
    }
    int ans = 0; // 记录连通块的个数
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1 && log[i][j] == false){ // 如果当前位置为1且未被访问过
                ans++; // 连通块数加1
                BFS(i, j); // 从该位置进行BFS遍历
            }
        }
    }
    cout << ans <<endl; // 输出连通块的个数
    return 0;
}
