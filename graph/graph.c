#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "graph.h"

bool visited[MAXVEX];


void CreatMGraph(struct MGraph * G){
    int i,j,k,w;
    printf("输入顶点以及边的个数:\n");
    scanf("%d,%d",&G->numberVer,&G->numberEd);
    printf("get value ver=%d,ed=%d\n",G->numberVer,G->numberEd);
    printf("输入每一个顶点的字母:\n");
    for(i=0;i<G->numberVer;i++) {
        scanf("%c",&G->vexs[i]);
    }
    for(i=0;i<G->numberVer;i++)
        for(j=0;j<G->numberVer;j++)
            G->arc[i][j]=INFINEIN;
    for(k=0;k<G->numberEd;k++){
        printf("输入(vi,vj)的下标以及w权重的值\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[i][j]=G->arc[j][i];
    }
}

void DFS(struct MGraph G,int i){
    visited[i]=true;
    printf("%c",G.vexs[i]);
    for(int j=0;j<G.numberVer;j++){
        if(G.arc[i][j]==1 && !visited[j]) DFS(G,j);
    }
}