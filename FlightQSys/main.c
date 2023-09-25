#include <stdio.h>
#include <stdlib.h>
#include "query_sys.h"


int main()
{
    
    struct Node * head;
    struct type_value * hash=NULL;
    InitNode(&head);
    int number,ret,position;
    Data_type e;
    while(1){
        printf("---------------------------------------------------\n");
        printf("|               输入0 为展示航班信息                 |\n");
        printf("|               输入1 为插入航班信息                 |\n");
        printf("|               输入2 为修改航班信息                 |\n");
        printf("|               输入3 为删除航班信息                 |\n");
        printf("|               输入4 为航班进行排序                 |\n");
        printf("|               输入-1为退出查询信息                 |\n");
        printf("---------------------------------------------------\n");
        ret=scanf("%d",&number);
        if(ret==0) {
            printf("输入非法,请重新输入\n");
            while ( getchar() != '\n' );
            continue;
        }
        if(number==-1) break;
        switch (number) {
            case 0:
                DisplayNode(head);
                break;
            case 1:
                printf("请输入插入位置:");
                scanf("%d",&position);
                printf("\n请输入航班号:");
                scanf("%s",e.number);
                printf("\n起始站->终点站:");
                scanf("%s%s",e.staddress,e.arraddress);
                printf("\n机型:");
                scanf("%s",e.TYPE);
                printf("\n票价:");
                scanf("%d",&e.value);
                printf("\n起飞时间,以小时来算:");
                scanf("%d",&e.stime);
                printf("\n结束时间,以小时来算:");
                scanf("%d",&e.atime);
                InsertNode(head, position, e);
                break;
            case 2:
                printf("请输入修改位置:");
                scanf("%d",&position);
                printf("\n请输入航班号");
                scanf("%s",e.number);
                ChangeNode(head, position, e);
                break;
            case 3:
                printf("请输入删除位置:");
                scanf("%d",&position);
                printf("\n");
                DeletNode(head, position);
                break;
            case 4:
                SortList(head);
                printf("排序后\n");
                DisplayNode(head);
                break;
            default:
                printf("输入的数字不在范围内,请重新输入\n");
                break;
        }
    }
    free(head);
    return 0;
}