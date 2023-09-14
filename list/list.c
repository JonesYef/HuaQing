#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


Statue GetElem(struct Node *head,int i,ElemType *e){
    struct Node  *p=head;
    p=p->next;//掠过头节点
    int j=1;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    *e=p->data;
    return OK;
}


Statue InsertList(struct Node *head,int i,ElemType e){
    struct Node * p=head;//从head节点开始遍历
    int j=1;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if(!p || j>i) return ERROR;
    struct Node * node=(struct Node *)malloc(sizeof(struct Node));
    node->data=e;
    node->next=p->next;
    p->next=node;
    return OK;
    
}

Statue DelList(struct Node * head,int i,ElemType * e){
    struct Node * p=head,*q;
    int j=1;
    while(p && j<i){
        p=p->next;
        j++;
    }
    if( !p || j>i) return ERROR;
    *e=p->next->data;
    q=p->next;
    p->next=p->next->next;
    free(q);
    return OK;
}

void CreatListTail(struct Node ** list,int n){
    struct Node * p,*q;
    srand(time(0));
    *list=(struct Node *)malloc(sizeof(struct Node));
    q=*list;
    for(int i=0;i<n;i++){
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=rand()%100+1;
        q->next=p;
        q=p;
    }
    q->next=NULL;


}

Statue ClearList(struct Node **list){
    struct Node * p=(*list)->next;
    struct Node * q;
    while(p){
        q=p;
        p=p->next;
        free(q);
    }
    (*list)->next=NULL;
    printf("Clear list done\n");
    return OK;
}

void DisplayList(struct Node * head){
    if(head==NULL) {
        printf("List is null\n");
        return;
    }
    struct Node *p=head->next;
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}



struct Node * ReverseList(struct Node * head){
    struct Node *p=head->next,*n=NULL,*q;
    
    while(p){
        q=p;
        p=p->next;
        q->next=n;
        n=q;
    }
    head->next=q;
    return head;

}