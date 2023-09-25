#include "stack.h"
#include <stdio.h>


int main()
{
    struct stack s;
    ElemType e;
    InitStack(&s,  4);
    DisplayStack(&s);
    PushStack(&s, 56);
    DisplayStack(&s);
    PullStack(&s, &e);
    DisplayStack(&s);
    printf("pull elem is %d\n",e);
    return 0;
}