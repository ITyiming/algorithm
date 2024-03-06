#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct student{
    char id[15];            // 学生注册号
    int score;              // 学生成绩
    int location_number;    // 考场编号
    int local_rank;         // 考场内排名
} stu[30010];

// 自定义比较函数，用于结构体数组的排序
bool cmp(student a, student b){
    if(a.score != b.score)  // 如果成绩不同，按成绩降序排列
        return a.score > b.score;
    else                     // 如果成绩相同，按注册号升序排列
        return strcmp(a.id, b.id) < 0;
}

int main(){
    int n, k, num = 0;
    cin >> n;   // 输入考场数量

    // 循环读入每个考场的学生信息
    for(int i = 1; i <= n; i++){
        cin >> k;   // 输入当前考场的学生数量
        for(int j = 1; j <= k; j++){
            cin >> stu[num].id >> stu[num].score;  // 输入学生的注册号和成绩
            stu[num].location_number = i;          // 设置考场编号
            num++;                                 // 更新学生数量
        }
        // 对当前考场的学生按成绩降序排序
        sort(stu + num - k, stu + num, cmp);
        // 设置当前考场学生的本地排名
        stu[num - k].local_rank = 1;
        for(int j = num - k + 1; j < num; j++){
            if(stu[j].score == stu[j - 1].score)   // 如果当前学生和前一个学生成绩相同
                stu[j].local_rank = stu[j - 1].local_rank;  // 本地排名相同
            else
                stu[j].local_rank = j + 1 - (num - k);   // 否则，本地排名为当前位置减去起始位置再加1
        }
    }

    cout << num << endl;   // 输出总学生数量

    // 对所有学生按照成绩和注册号排序
    sort(stu, stu + num, cmp);

    int r = 1;   // 记录当前全局排名
    // 遍历输出所有学生的信息
    for(int i = 0; i < num; i++){
        if(i > 0 && stu[i].score != stu[i - 1].score)  // 如果当前学生的成绩和上一个学生的成绩不同
            r = i + 1;                                  // 更新全局排名为当前位置加1
        cout << stu[i].id << " " << r << " " << stu[i].location_number << " " << stu[i].local_rank << endl;  // 输出学生信息
    }

    return 0;
}

