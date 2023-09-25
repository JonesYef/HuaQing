#include <stdio.h>
#include <stdlib.h>
#include "list_double.h"


int main()
{
    struct ListDouble * head;
    Elemtype e;
    InitListDouble(&head, 5);
    DisplayListDouble(head);
    
    InsertListdouble(head, 5, 45);
    DisplayListDouble(head);

    DeletListDouble(head, 4);
    DisplayListDouble(head);

    printf("%d\n",FindElemListDouble(head, 56));

    return 0;
}

