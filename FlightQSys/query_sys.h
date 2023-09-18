
/*
1）	信息录入
2）	信息显示（按照起飞时间先后顺序显示）
3）	信息查询（可根据不同的关键字进行查询）
4）	信息修改
5）	信息删除

1）	使用链表对录入的信息进行存储
2）	对录入的信息进行排序（可按起飞时间进行排序）
3）	使用make管理编译工程项目(参考:实验14.2)

*/
#ifndef USER_QUERY_SYS__H_
#define USER_QUERY_SYS__H_

#include <stdbool.h>


typedef  struct flight       //航班信息数据结构
{   
    char number[10];    //航班号    
    char staddress[10];   //起点站    
    char arraddress[10];   //终点站    
    char DATE[10];       //班期    
    char TYPE[4];       //机型    
    int stime;          //起飞时间    
    int atime;          //到达时间    
    int value;           //票价     
}Data_type;

struct Node   //双向链表结点
{            
    Data_type info;       
    struct Node *next,*prev;   
};  



/*传入一个头节点来作为虚拟头节点使用*/
void InitNode(struct Node **list);

/*插入操作,插入在航班号的后面*/
void InsertNode(struct Node * head,int position,Data_type e);

/*显示信息*/
void DisplayNode(struct Node * head);

/*修改位置为position处的元素*/
void ChangeNode(struct Node *head,int position,Data_type e);

/*删除位置为position处的元素*/
void DeletNode(struct Node * head,int position);

/*是否为空,为空返回true,不为空返回false*/
bool EmptyList(struct Node *head);

/*排序,按照时间顺序来排,小的在前面*/
void SortList(struct Node * head);



#endif