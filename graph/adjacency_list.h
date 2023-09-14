#ifndef USER_ADJ_LIST__H_
#define USER_ADJ_LIST__H_


#define MAXVEX 100
typedef char VertexType;
typedef int EgdeType;

/*链表节点*/
struct Adj_Node{
    int index;//下标
    EgdeType wight;//权重
    struct Adj_Node * next;//下一个无向图邻接点
};

/*数组node*/
struct arr_node{
    VertexType data;//顶点元素
    struct Adj_Node * head;//空的head节点
};

struct Adj_list{
    struct arr_node arr[MAXVEX];
    int numberVer,numberEdge;
};


void CreatAlgraph(struct Adj_list * g );

#endif