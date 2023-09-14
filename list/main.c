#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main()
{
    ElemType e;
    struct Node * head=NULL;
    CreatListTail(&head, 5);
    DisplayList(head);
    //删除第4个位置的元素
    DelList(head, 4, &e);
    printf("The postion %d del elem is %d\n",4,e);
    DisplayList(head);

    //插入元素在第3个位置前面
    InsertList(head, 3, 45);
    DisplayList(head);

    //返回第5个位置的元素
    GetElem(head, 5, &e);
    printf("get elem is %d\n",e);
    DisplayList(head);

    //删除整个链表test
    //ClearList(&head);
    //DisplayList(head);

    /*测试算法*/
    head=ReverseList(head);
    DisplayList(head);

    return 0;
}