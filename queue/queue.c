#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


void InitQueue(struct Queue *q){
    q->front=q->behind=0;
    q->data=(int *)malloc(sizeof(int)*MAXSIZE);
    DEBUG("初始化完毕\n");
}

void InQueue(struct Queue *q,int data){
    if((q->behind+1)%MAXSIZE==q->front) 
    {
        perror("队伍已经满了\n");
        return;
    }
    q->data[q->behind]=data;
    q->behind=(q->behind+1)%MAXSIZE;
    DEBUG("入队完成\n");

}

void DeQueue(struct Queue *q,int *e)
{
    if(q->front==q->behind) 
    {
        perror("队伍为空\n");
        return;
    }
    *e=q->data[q->front];
    q->front=(q->front-1)%MAXSIZE;
    DEBUG("出队完成\n");
}

void DisplayQueue(struct Queue *q){
    int i=(q->behind-1)%MAXSIZE;
    while(i!=q->front)
    {
        printf("%d\n",q->data[i]);
        i=(i+1)%MAXSIZE;
    }
    
           
}