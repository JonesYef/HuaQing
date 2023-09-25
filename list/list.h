#ifndef __USER_LIST__H_
#define __USER_LIST__H_

#define OK 1;
#define ERROR 0;


typedef int Statue;
typedef int ElemType;

struct Node{
    int data;
    struct Node * next;
};

/*返回第i个位置的元素用e来存储*/
Statue GetElem(struct Node *head,int i,ElemType *e);

/*在i位置前面插入元素e*/
Statue InsertList(struct Node *head,int i,ElemType e);

/*删除第i个位置的元素并用e来保存*/
Statue DelList(struct Node * head,int i,ElemType * e);

/*随机产生n个元素的值,建立带表头的单链表*/
void CreatListTail(struct Node ** list,int n);

/*清空链表*/
Statue ClearList(struct Node **list);

/*显示链表的数据*/
void DisplayList(struct Node * head);

/*相关算法操作********************************************************************/

/*逆序链表*/
struct Node * ReverseList(struct Node * head);





#endif