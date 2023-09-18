#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "query_sys.h"



const char *location[10]={"深圳","武汉","成都","北京","上海",
                    "广州","南昌","西安","合肥","杭州"};

char * flight_type[5]={"C919","ARJ21","MA60","MA600","MA700"};
const char *flight_number[5]={"001","002","003","004","005"};
const int price[5]={100,500,230,456,132};
time_t diff[10],pre,aft;


void InitNode(struct Node **list)
{
    (*list)=(struct Node *)malloc(sizeof( struct Node ));
    (*list)->next=(*list);
    (*list)->prev=(*list);

    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        struct Node * p= (struct Node *)malloc(sizeof( struct Node ));
        strcpy(p->info.staddress, location[i]);
        strcpy(p->info.arraddress, location[i+4]);
        strcpy(p->info.TYPE, flight_type[i]);
        strcpy(p->info.number,flight_number[i]);
        p->info.value=price[i];
        p->info.stime=rand()%12+1;
        p->info.atime=rand()%12+3;

        p->next=(*list);
        p->prev=(*list)->prev;
        (*list)->prev->next=p;
        (*list)->prev=p;
    }

}

void InsertNode(struct Node * head,int position,Data_type e)
{
    struct Node *p=head->next;
    int i=1;
    while(i<position && p!=head) p=p->next;
    struct Node * n=(struct Node *)malloc(sizeof(struct Node));
    n->info=e;

     
    n->next=p->next;
    n->prev=p;
    p->next->prev=n;
    p->next=n;

}

void DisplayNode(struct Node * head){
    struct Node *p=head->next;
    int i=1;
    char buf[100];
    time_t ticks;
    time(&ticks);
    while(p!=head){
        printf("航班号:%s\t",p->info.number);
        printf("起点站:%s--->",p->info.staddress);
        printf("终点站:%s\t\n",p->info.arraddress);
        printf("机型 %s\t",p->info.TYPE);
        printf("票价:%d\t",p->info.value);
        printf("\n");
        ticks=rand()%43200*2+3600*p->info.stime;
        snprintf(buf, sizeof(buf), "%.24s",ctime(&ticks));
        printf("%s\t",buf);
        pre=ticks;//时间处理
        


        ticks+=p->info.atime*3600;
        snprintf(buf, sizeof(buf), "%.24s",ctime(&ticks));
        printf("%s\n",buf);
        aft=ticks;
        diff[i++]=aft-pre;


        p=p->next;
        printf("---------------------------------------------------------\n");
    }

}

bool EmptyList(struct Node *head)
{
    if(head->next==head || head->prev==head) return true;
    return false;
}

void ChangeNode(struct Node *head,int position,Data_type e)
{
    if (EmptyList(head)) {
        printf("航班为空,修改错误\n");
        return;
    }
    struct Node *p=head->next;
    int i=1;
    while(i<position && p!=head) p=p->next;
    if(i<position) head->prev->info=e;
    else p->info=e;
}

void DeletNode(struct Node * head,int position)
{
    if(EmptyList(head)) {
        printf("航班为空,删除错误\n");
        return;
    }
    struct Node * p=head;
    int i=0;
    while(i<position-1 && p!=head) p=p->next;
    if(i<position) {
        head->prev->prev->next=head;
        head->prev=head->prev->prev;
    }
    else {
        p->next->next->prev=p;
        p->next=p->next->next;
    }

}


void SortList(struct Node * head){
//线性表的排序,采用冒泡排序,直接遍历链表
    struct Node * L = head->next;
    //作为一个临时量
    struct Node * p=L->next;
    struct Node * tmp=p;
    //如果链表为空直接返回
    if(head->next==head) return;

    while(L!=head)
    {
        while(p!=head)
        {
            if((L->info.atime - L->info.stime) > (p->info.atime - p->info.stime))
            {    
                tmp->info=L->info;
                L->info=p->info;
                p->info=tmp->info;
            }
            p=p->next;
        }
        L=L->next;
    }
}