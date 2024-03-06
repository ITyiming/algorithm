#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct student{
    char id[15];            // ѧ��ע���
    int score;              // ѧ���ɼ�
    int location_number;    // �������
    int local_rank;         // ����������
} stu[30010];

// �Զ���ȽϺ��������ڽṹ�����������
bool cmp(student a, student b){
    if(a.score != b.score)  // ����ɼ���ͬ�����ɼ���������
        return a.score > b.score;
    else                     // ����ɼ���ͬ����ע�����������
        return strcmp(a.id, b.id) < 0;
}

int main(){
    int n, k, num = 0;
    cin >> n;   // ���뿼������

    // ѭ������ÿ��������ѧ����Ϣ
    for(int i = 1; i <= n; i++){
        cin >> k;   // ���뵱ǰ������ѧ������
        for(int j = 1; j <= k; j++){
            cin >> stu[num].id >> stu[num].score;  // ����ѧ����ע��źͳɼ�
            stu[num].location_number = i;          // ���ÿ������
            num++;                                 // ����ѧ������
        }
        // �Ե�ǰ������ѧ�����ɼ���������
        sort(stu + num - k, stu + num, cmp);
        // ���õ�ǰ����ѧ���ı�������
        stu[num - k].local_rank = 1;
        for(int j = num - k + 1; j < num; j++){
            if(stu[j].score == stu[j - 1].score)   // �����ǰѧ����ǰһ��ѧ���ɼ���ͬ
                stu[j].local_rank = stu[j - 1].local_rank;  // ����������ͬ
            else
                stu[j].local_rank = j + 1 - (num - k);   // ���򣬱�������Ϊ��ǰλ�ü�ȥ��ʼλ���ټ�1
        }
    }

    cout << num << endl;   // �����ѧ������

    // ������ѧ�����ճɼ���ע�������
    sort(stu, stu + num, cmp);

    int r = 1;   // ��¼��ǰȫ������
    // �����������ѧ������Ϣ
    for(int i = 0; i < num; i++){
        if(i > 0 && stu[i].score != stu[i - 1].score)  // �����ǰѧ���ĳɼ�����һ��ѧ���ĳɼ���ͬ
            r = i + 1;                                  // ����ȫ������Ϊ��ǰλ�ü�1
        cout << stu[i].id << " " << r << " " << stu[i].location_number << " " << stu[i].local_rank << endl;  // ���ѧ����Ϣ
    }

    return 0;
}

