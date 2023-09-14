#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

void preOredertraver(BitTree node){
    if(node==NULL) return ;
    printf("%c",node->data);
    preOredertraver(node->lchild);
    preOredertraver(node->rchild);
}

void inOrderTraver(BitTree node){
    if(node==NULL) return;
    inOrderTraver(node->lchild);
    printf("%c",node->data);
    inOrderTraver(node->rchild);
}

void posetTraver(BitTree node){
    if(node==NULL) return;
    posetTraver(node->lchild);
    posetTraver(node->rchild);
    printf("%c",node->data);
}

void CreatTree(BitTree *node){
    TElemType ch;
    scanf("%c",&ch);
    if(ch=='#') *node=NULL;
    else{
        *node=(BitTree)malloc(sizeof(BitNode));
        (*node)->data=ch;
        CreatTree(&(*node)->lchild);
        CreatTree(&(*node)->rchild);
    }
}