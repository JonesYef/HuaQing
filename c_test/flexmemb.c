#include <stdio.h>
#include <stdlib.h>

/*
    对变长数组的使用
*/

struct te{
    int i;
    int na[];
};

struct flex{
    int count;
    double average;
    double scores[];
};

void showFlew(const struct flex *);

int main(int argc,char ** argv)
{
    int n=8,tot=0;
    printf("没有初始化时的struct sizeof为多少:%lu\n",sizeof(struct flex));
    struct flex * p=(struct flex *)malloc(sizeof(struct flex)+n*sizeof(double));
    p->count=n;
    for(int i=0;i<n;i++){
        p->scores[i]=20.0-i;
        tot+=p->scores[i];
    }
    p->average=(tot+0.0)/n;
    showFlew(p);
    free(p);
    return 0;

}


void showFlew(const struct flex * p){
    printf("Sorces :");
    for (int i=0; i<p->count; i++) {
        printf("%g ",p->scores[i]);
    }
    printf("\nAverage : %g",p->average);
}