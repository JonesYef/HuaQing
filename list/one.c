#include <stdio.h>
#include <stdlib.h>
#include "list_cir.h"


int main()
{
    struct ListCir * head;
    InitListCir(&head,  5);
    Display(head);

    return 0;
}