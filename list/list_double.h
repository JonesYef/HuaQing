#ifndef __USER_LIST_DOUBLE__H_
#define __USER_LIST_DOUBLE__H_

typedef int Elemtype;
typedef int Bool;
#define  true 1
#define false 0

#ifdef MYDEBUG 
#define DEBUG(arg...) {\
printf("[debug]:%s:%s:%d ---->",__FILE__,__FUNCTION__,__LINE__);\
printf(arg);\
fflush(stdout);\
} 
#else 
#define DEBUG(arg...) {} 
#endif



/*两个虚拟节点*/
struct ListDouble{
    Elemtype data;
    struct ListDouble * prev;
    struct ListDouble * next;
};

/*对双向链表进行初始化,需要传入一个表头*/
void InitListDouble(struct ListDouble ** list,int n);

/*遍历双向链表*/
void DisplayListDouble(struct ListDouble * head);

/*插入操作,在position位置插入元素,从1开始*/
void InsertListdouble(struct ListDouble * head,int position,Elemtype e);

/*删除position处的元素*/
void DeletListDouble(struct ListDouble * head,int position);

/*查找是否存在指定元素的值*/
Bool FindElemListDouble(struct ListDouble * head,Elemtype e);

/*删除整个链表*/
void DestroyListDouble(struct ListDouble ** list);


#endif