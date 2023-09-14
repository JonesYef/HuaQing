#include<stdlib.h>
#include<stdio.h>
#include"tree.h"



int main()
{
    BitTree node;
    CreatTree(&node);
    preOredertraver(node);
    printf("/ndone");
    return 0;
}


