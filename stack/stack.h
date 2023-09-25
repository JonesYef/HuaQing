#ifndef __USER_STACK__H_
#define __USER_STACK__H_

#define MAXSIZE 10
typedef int ElemType;

struct stack
{
    ElemType data[MAXSIZE];
    int top;
};

void InitStack(struct stack *s,int n);

void PushStack(struct stack *s,ElemType e);

void PullStack(struct stack *s,ElemType *e);

void DisplayStack(struct stack *s);


#endif