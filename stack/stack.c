#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"



void InitStack(struct stack *s,int n)
{
    if(n>=MAXSIZE) n=MAXSIZE;
    srand(time(0));
    s->top=-1;//对数组位置的定义
    for(int i=0;i<n;i++)
    {
        s->top++;
        s->data[s->top]=(ElemType)rand()%100+1;
    }

}

void PushStack(struct stack *s,ElemType e)
{
    if(s->top+1==MAXSIZE) {
        perror("stack is full,can't push elem to stack\n");
        return;
    }
    s->top++;
    s->data[s->top]=e;
    printf("push elem done\n");
}

void PullStack(struct stack *s,ElemType *e)
{
    if(s->top==-1) {
        perror("stack is empty,can't pull elem form stack\n");
        return;
    }
    *e=s->data[s->top];
    s->top--;
    printf("pull elem  done\n");
}

void DisplayStack(struct stack *s)
{
    for(int i=s->top;i>=0;i--) printf("|%d|\n",s->data[i]);
}