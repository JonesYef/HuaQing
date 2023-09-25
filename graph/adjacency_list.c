#include<stdlib.h>
#include<stdio.h>
#include"adjacency_list.h"


void CreatAlgraph(struct Adj_list * g ){
    int i,j,k;
    struct Adj_Node * e;
    printf("输入顶点个和边的个数\n");
    scanf("%d,%d",&g->numberVer,&g->numberEdge);
    printf("请连续输入顶点的值:\n");
    for(i=0;i<g->numberVer;i++){
        scanf("%c",&g->arr[i].data);
        g->arr[i].head=NULL;//先将其设置为null
    }
    for(k=0;k<g->numberEdge;k++){
        printf("输入边表(vi,vj)的序号:\n");
        scanf("%d,%d",&i,&j);
        //对i的节点进行链表节点的补充
        e=(struct Adj_Node *)malloc(sizeof(struct Adj_Node));
        e->index=j;
        e->next=g->arr[i].head;
        g->arr[i].head=e;

        //对于同样的j的节点进行链表添加
        e=(struct Adj_Node *)malloc(sizeof(struct Adj_Node ));
        e->index=i;
        e->next=g->arr[j].head;
        g->arr[j].head=e;
    }
}