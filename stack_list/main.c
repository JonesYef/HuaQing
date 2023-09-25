#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"


int main()
{
    struct StackList * s;
    InitStackList(&s);
    PushStackList(&s, 5);
    PushStackList(&s, 74);
    PushStackList(&s, 88);
    DisplayStackList(s);

    return 0;
}
