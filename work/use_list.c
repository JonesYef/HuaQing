#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


struct list_data{

    int data;
    struct list_head  d_head;
};


int main()
{   
    struct list_data * head=(struct list_data *)malloc(sizeof(struct list_data));
    head->data=0;
    INIT_LIST_HEAD(&head->d_head);
    struct list_data * head1=(struct list_data *)malloc(sizeof(struct list_data));
    struct list_data * head2=(struct list_data *)malloc(sizeof(struct list_data));
    struct list_data * head3=(struct list_data *)malloc(sizeof(struct list_data));
    struct list_data * head4=(struct list_data *)malloc(sizeof(struct list_data));
    head1->data=10;
    head2->data=20;
    head3->data=30;
    head4->data=40;


    list_add_tail(&head1->d_head, &head->d_head);
    list_add_tail(&head2->d_head, &head->d_head);
    list_add_tail(&head3->d_head, &head->d_head);
    list_add_tail(&head4->d_head, &head->d_head);


    list_for_each_entry(head,&head->d_head,d_head){
        printf("%d\n",head->data);
    }
    free(head);
    return 0;
}






