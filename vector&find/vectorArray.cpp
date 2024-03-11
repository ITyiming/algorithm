#include <iostream>
#include <vector>
using namespace std;

int main(){
    // 定义一个二维 vector，每个元素是一个 vector<int>。释：matrix，矩阵
    vector<vector<int>> matrix;
    
    // 初始化二维数组
    int rows = 3;
    int cols = 4;
    for (int i = 0;i < rows;++i){
        vector<int> row; // 定义一行
        for (int j = 0; j < cols; ++j){
            row.push_back(i*cols + j); // 向行添加元素
        }
        matrix.push_back(row); // 将行添加道二维数组中
    }

    // 访问二维数组元素
    for(int i = 0; i < rows; ++i){
        for(int j=0; j < cols; ++j){
            cout << matrix[i][j] << " "; // 输出元素值
        }
        cout << endl;
    }
    return 0;
}