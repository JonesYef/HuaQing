#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "list_double.h"






void InitListDouble(struct ListDouble ** list,int n){
    struct ListDouble * node=(struct ListDouble *)malloc(sizeof(struct ListDouble));
    node->prev=(*list);
    node->next=NULL;
    (*list)->next=node;
    (*list)->prev=NULL;


    srand(time(0));
    struct ListDouble * p=(*list);
    for(int i=0;i<n;i++){
        struct ListDouble * node=(struct ListDouble *)malloc(sizeof(struct ListDouble));
        assert(node!=NULL);
        node->data=(Elemtype)rand()%200+1;
        node->next=p->next;
        node->prev=p;
        p->next->prev=node;
        p->next=node;
    }   
    //printf("初始化完成\n");
}


void DisplayListDouble(struct ListDouble * head){
    struct ListDouble * p=head->next;
    while(p->next){
        printf(" %d ->",p->data);
        p=p->next;
    }
    printf(" NULL\n");

}


void InsertListdouble(struct ListDouble * head,int position,Elemtype e){
    assert(position>0);
    unsigned int n=1;
    struct ListDouble * node=(struct ListDouble *)malloc(sizeof(struct ListDouble ));
    node->data=e;
    struct ListDouble * p=head;
    while(p->next->next && n<position){
        p=p->next;
        n++;
    }
    node->next=p->next;
    node->prev=p;
    p->next->prev=node;
    p->next=node;

}


void DeletListDouble(struct ListDouble * head,int position){
    assert(position>0);
    unsigned int n=0;
    struct ListDouble * p=head,*q;
    while(p->next->next && n<position){
        p=p->next;
        n++;
    }
    q=p;
    p->next->prev=p->prev;
    p->prev->next=p->next;
    free(q);
}

Bool FindElemListDouble(struct ListDouble * head,Elemtype e){
    struct ListDouble * p =head->next;
    while(p->next){
        if(p->data==e) return true;
        p=p->next;
    }
    return false;
}

void DestroyListDouble(struct ListDouble ** list){
    struct ListDouble * p=(*list)->next,*q;
    while(p){
        q=p;
        p=p->next;
        free(q);
    }

}