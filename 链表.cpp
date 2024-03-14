#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node* next;
};
//创建链表（关键函数）
node* create(int array[]){
    node *p,*pre,*head;//pre保存当前结点数据，head为头节点
    head = new node;//创建头结点
    head->next =NULL;//头结点不需要数据域，指针域初始为NULL
    pre=head;//记录pre为head
    for(int i=0;i<5;i++){
        p=new node;//新建结点
        //将array[i]赋给新建结点作为数据域。
        p->data=array[i];
        p->next=NULL;//新结点的指针域设为NULL
        pre->next=p;//把pre设为p，作为下个结点的前驱结点
    }
    return head;//返回头指针；
}
int main(){
    int array[5]={5,3,6,1,2};
    node* L=create(array);//新建链表，返回头指针head赋给L;
    L=L->next;//从第一个结点开始有数据域
    while(L!=NULL){
        cout<<L->data;
        L=L->next;
    }
    return 0;
}