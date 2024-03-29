#include<iostream>
using namespace std;
const int N = 2005;
int a[N][N];

// 执行操作，将操作范围内的四个顶点分别加减 1，表示取反操作
void insert(int x1, int y1, int x2, int y2){
    a[x1][y1] += 1;
    a[x2 + 1][y1] -= 1;
    a[x1][y2 + 1] -= 1;
    a[x2 + 1][y2 + 1] += 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;

    // 执行操作，更新数组 a
    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2);
    }

    // 根据四个角的前缀和求解每个位置上的棋子颜色，并输出结果
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] % 2 ;
        }
        cout << endl;
    }
    return 0;
}
