#ifndef _USER_TREE__H_
#define _USER_TREE__H_


typedef char TElemType;

typedef struct BitNode{
    TElemType data;
    struct  BitNode * lchild;
    struct  BitNode * rchild;
}BitNode,*BitTree;

void preOredertraver(BitTree node);

void inOrderTraver(BitTree node);

void posetTraver(BitTree node);

void LayerTraversal(BitTree node);

void CreatTree(BitTree *node); 

#endif