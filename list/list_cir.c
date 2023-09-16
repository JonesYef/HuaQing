#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_cir.h"


void InitListCir(struct ListCir ** list,int n){

    srand(time(0));
    (*list)->data=0;
    (*list)->next=(*list);
    (*list)->prev=(*list);

    for(int i=0;i<n;i++){
        struct ListCir * node=(struct ListCir*)malloc(sizeof(struct ListCir));
        node->data=(ElemType)rand()%100+1;
        node->next=(*list)->next;
        node->prev=(*list);
        (*list)->next->prev=node;
        (*list)->next=node;
    }


}

void Display(struct ListCir * head){
    struct ListCir * p=head->next;
    while(p->next!=head){
        printf(" %d ->",p->data);
        p=p->next;
    }
    printf("%d -> NULL\n",p->data);

}