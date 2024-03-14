#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector<int> ids;

    for (int i = 0; i < N; ++i) {
        int num;
        while (cin >> num) {
            ids.push_back(num);
            if (cin.get() == '\n') break;
        }
    }

     // 对所有ID进行排序
    sort(ids.begin(), ids.end());

    int duplicateID = 0, missingID = 0;

    // 找出重号和断号
    for (int i = 1; i < ids.size(); ++i) {
        if (ids[i] == ids[i - 1]) {
            duplicateID = ids[i];
        } else if (ids[i] > ids[i - 1] + 1) {
            missingID = ids[i - 1] + 1;
        }
    }

    cout << missingID << " " << duplicateID << endl;

    return 0;
}

