#ifndef __USER_STACK_LIST__H_
#define __USER_STACK_LIST__H_


struct StackList{
    int data;
    struct StackList *next;
};

void InitStackList(struct StackList **top);

void PushStackList(struct StackList **top,int data);

void PullStackList(struct StackList **top,int *e);

void DisplayStackList(struct StackList *top);

#endif
