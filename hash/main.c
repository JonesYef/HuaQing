#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main()
{
    struct HashTable h;
    InitHashTable(&h);
    
    InsertHash(&h, 8);
    InsertHash(&h, 59);
    InsertHash(&h, 120);
    InsertHash(&h, 78);

    int addr;
    Statue test= SearchElem(h,78,&addr);
    printf("search 54 is %d\n",test);

    return 0;
}