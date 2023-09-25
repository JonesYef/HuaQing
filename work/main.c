#include <stdlib.h>
#include <stdio.h>
#include "arr.h"


int main()
{
    struct arr st;
    InitArr(&st);
    InserRandom(&st, 10);
    DisplayArr(&st);
    InsertArr(&st,2,40);
    DisplayArr(&st);
    DelArr(&st, 5);
    DisplayArr(&st);
    return 0;

}