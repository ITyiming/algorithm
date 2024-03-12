#include <iostream>
using namespace std;

int countSquares(int length, int width) {
    int count = 0;
    while (length != width) {
        if (length > width) {
            length -= width;
        } else {
            width -= length;
        }
        count++;
    }
    // 最后一次切割会得到一个正方形，加上这个正方形
    count++;
    return count;
}

int main() {
    int length = 2019, width = 324;
    int number = countSquares(length, width);
    cout << "小明最终会切出 " << number << " 个正方形。" << endl;
    return 0;
}
