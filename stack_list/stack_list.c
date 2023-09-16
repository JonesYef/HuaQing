#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"


void InitStackList(struct StackList **top)
{
    (*top)=(struct StackList *)malloc(sizeof(struct StackList));
    //(*top)=NULL;
    (*top)->next=NULL;
    (*top)->data=-1;
}

void PushStackList(struct StackList **top,int data)
{
    struct StackList * p=(struct StackList *)malloc(sizeof(struct StackList));
    p->data=data;
    p->next=(*top);
    (*top)=p;
}

void PullStackList(struct StackList **top,int *e)
{
    if((*top)==NULL) {
        perror("emty\n");
        return;
    }
    struct StackList * p;
    p=(*top);
    (*top)=(*top)->next;
    free(p);
}

void DisplayStackList(struct StackList *s)
{
    struct StackList * p=s;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }


}