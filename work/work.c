#include <stdio.h>
#include <stdlib.h>
#include "arr.h"


int main()
{
    Elemtype e;
    int ch;
    int index;
    struct arr st;
    InitArr(&st);
    InserRandom(&st,10);

    while(1){
        printf("输入正整数插入元素,输入负数删除元素,输入0退出循环\n");
        scanf("%d",&ch);
        if(ch==0){
            printf("退出循环\n");
            break;
        }
        else if(ch>0){

            printf("输入要插入的位置(从1开始)和元素\n");
            printf("现在数组的元素分布\n");
            DisplayArr(&st);
            scanf("%d%d",&index,&e);
            InsertArr(&st, index,e);
            DisplayArr(&st);
        }
        else if(ch<0){
            printf("输入要删除的位置(从1开始)和元素\n");
            printf("现在数组的元素分布\n");
            DisplayArr(&st);
            scanf("%d",&index);
            DelArr(&st, index);
            DisplayArr(&st);
        }

    }

    return 0;
}