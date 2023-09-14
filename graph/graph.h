#ifndef _USER_GRAPH__H_
#define _USER_GRAPH__H_

#define MAXVEX 100
#define INFINEIN 65535
typedef char VType;
typedef int EType;

struct MGraph{
    VType vexs[MAXVEX];
    EType arc[MAXVEX][MAXVEX];
    int numberVer,numberEd;
};

void CreatMGraph(struct MGraph * G);

void DFS(struct MGraph G,int i);

#endif