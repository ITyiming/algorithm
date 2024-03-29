#include<iostream>
using namespace std;
const int N = 1e9 + 5;
int n, m, p;
int a[N][N], b[N][N];
void insert(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x2 + 1][y1] -=c;
    b[x1][y2 + 1] -=c;
    b[x2 + 1][y2 + 1] +=c;
}
int main(){
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }
    }
    cin >> p;
    int x1, y1, x2, y2, c;
    for(int i = 1; i <= p; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}