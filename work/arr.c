#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arr.h"

static int arrsize=MAXSIZE;




Statue InitArr(struct arr * st){
    st->p=(Elemtype *)malloc(sizeof(Elemtype)*MAXSIZE);
    st->lenght=0;
    return OK;
}

Statue InsertArr(struct arr * st,int i,Elemtype e){
    
    if(i<0 || i>st->lenght) return ERROR;
    if(st->lenght==arrsize) {
        perror("申请的空间不足需要扩容\n");
        if(realloc(st->p, sizeof(Elemtype)*MAXSIZE)==NULL) perror("分配失败\n");
        arrsize+=MAXSIZE;
    }
    st->lenght++;
    int j=st->lenght;
    for(;j>i-1;j--)  st->p[j]=st->p[j-1];
    st->p[j]=e;
    return OK;
}

void DisplayArr(struct arr * st){
    for(int j=0;j<st->lenght;j++)
    {
        printf("%d ",st->p[j]);
    }
    printf("\n");
    
}

void InserRandom(struct arr * st,int n){
    
    srandom(time(0));
    for(int i=0;i<n;i++)
    {
        st->p[i]=rand()%100+1;
        st->lenght++;
    }
}

Statue GetElem(struct arr * st,int i,Elemtype *e){

    if(i<0 || i>st->lenght) {
        perror("i的index错误");
        return ERROR;
    }
    *e=st->p[i];
    return OK;
}

Statue DelArr(struct arr * st,int i){
    if(i<0||i>st->lenght) return ERROR;
    for(int j=i-1;j<st->lenght-1;j++){
        st->p[j]=st->p[j+1];
    }
    st->lenght--;
    return OK;
}