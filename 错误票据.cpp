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

    // ������ID��������
    sort(ids.begin(), ids.end());

    int duplicateID = 0, missingID = 0;

    // �ҳ��غźͶϺ�
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

