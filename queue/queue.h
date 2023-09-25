#ifndef __USER_QUEUE__H_
#define __USER_QUEUE__H_


#define MAXSIZE 11

#ifdef MYDEBUG 
#define DEBUG(arg...) {\
printf("[debug]:%s:%s:%d ---->",__FILE__,__FUNCTION__,__LINE__);\
printf(arg);\
fflush(stdout);\
} 
#else 
#define DEBUG(arg...) {} 
#endif


struct Queue{
    int *data;
    int front;//指向队头
    int behind;//指向队尾位置
};

void InitQueue(struct Queue *q);

void InQueue(struct Queue *q,int data);

void DeQueue(struct Queue *q,int *e);

void DisplayQueue(struct Queue *q);

#endif

