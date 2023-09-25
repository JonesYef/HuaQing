#include<stdlib.h>
#include<stdio.h>

#include"graph.h"


struct MGraph G;
int main()
{
    
    CreatMGraph(&G);
    DFS(G,0);

    return 0;
}