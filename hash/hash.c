#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

static int m=0;


Statue InitHashTable(struct HashTable * h   ){
    m=HASHSIZE;
    h->count=m;
    h->elem=(int *)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        h->elem[i]=NULLKEY;
    }
    return OK;
}

int Hash(int key){
    return key%(m);
}

void InsertHash(struct HashTable * h,int key){
    int addr=Hash(key);
    while(h->elem[addr]!=NULLKEY) addr=(addr+1)%(m);
    h->elem[addr]=key;
}


Statue SearchElem(struct HashTable h,int key,int *addr){
    *addr=Hash(key);
    while(h.elem[*addr]!=key){
        *addr=(*addr+1)%m;
        if(h.elem[*addr]==NULLKEY || *addr==Hash(key)) return FAIL;
    }
    return SUCCESS;
}