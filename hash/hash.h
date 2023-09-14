#ifndef __USER_HASH__H_
#define __USER_HASH__H_

#define SUCCESS 1
#define FAIL 0
#define OK 1
#define ERROR 0
#define HASHSIZE 12
#define NULLKEY -32768

typedef int Statue;


struct HashTable{
    int *elem;//数组保存hash值的地方
    int count;//hash数组的大小
};


Statue InitHashTable(struct HashTable *);

int Hash(int key);

void InsertHash(struct HashTable * h,int key);

Statue SearchElem(struct HashTable h,int key,int *addr);

#endif