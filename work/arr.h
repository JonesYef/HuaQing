#ifndef __USER_ARR__H_
#define __USER_ARR__H_


typedef int Statue;
typedef int Elemtype;

#define MAXSIZE 30
#define OK 1
#define ERROR 0

struct arr{
    Elemtype *p;//数组的名字
    int lenght;//当前的有效长度
};


Statue InitArr(struct arr * st);

/*在第i个位置插入元素e*/
Statue InsertArr(struct arr * st,int i,Elemtype e);

/*获取第i个位置的元素,并用e接受*/
Statue GetElem(struct arr * st,int i,Elemtype *e);

/*用与在数组中随机加入n个随机数*/
void InserRandom(struct arr * st,int n);

/*删除第i个位置的元素*/
Statue DelArr(struct arr * st,int i);

/*显示数组的元素*/
void DisplayArr(struct arr * st);



#endif