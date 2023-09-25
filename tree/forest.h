#ifndef _USER_FOREST__H_
#define _USER_FOREST__H_

#define MAXSIZE 20
typedef int ElemType;

/*对链表节点的定义*/
typedef struct child_node{
    int index;
    struct child_node *next;
}child_node;

typedef struct 
{
    ElemType data;
    child_node * head;
}tree_node;

typedef struct  forest{
    tree_node  nodes[MAXSIZE];
    int r,n;  //对树的节点的度和深度
}forest;




#endif