#ifndef __USER_LIST_CIR__H_
#define __USER_LIST_CIR__H_

typedef int ElemType;

struct ListCir{
    ElemType data;
    struct ListCir * prev;
    struct ListCir * next;
};

/*初始化双向循环链表,并随机生成n个节点*/
void InitListCir(struct ListCir ** list,int n);

/*插入在head后面,*/
void InsertListCir(struct ListCir *head,ElemType e);

void Display(struct ListCir *head);


#endif