#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, a, b) for(int i = a; i < b; i++)
#define x first 
#define y second 

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1e5 + 10;

PII a[N]; // 每个数的花费和出现的次数
int dic[10]; // 每个数实际出现的次数
int n;

int main(){
    cin >> n;
    rep(i, 1, n + 1)
        cin >> a[i].y >> a[i].x, dic[a[i].y]++;

    sort(a + 1, a + 1 + n); // 按照花费从小到大进行排序

    LL res = 0; // 结果初始化为0
    int cnt = n / 10; // 每个数字应该出现的次数
    rep(i, 1, n + 1){
        if(dic[a[i].y] > cnt){ // 如果某个数字的实际出现次数大于每个数字应该出现的次数
            res += a[i].x; // 将该数字的花费计算进其中
            dic[a[i].y]--; // 出现次数减一，表示已经处理了一个该数字
        }
    }
    
    cout << res << endl;
    return 0;
}