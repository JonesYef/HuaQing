#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main()
{
    struct Queue q;
    InitQueue(&q);
    InQueue(&q, 5);
    InQueue(&q, 4);
    InQueue(&q, 2);
    InQueue(&q, 3);
    DisplayQueue(&q);


    return 0;
}