#include <stdio.h>

int a=123;

void func(int *p){
    p=&a;
    printf("%p\n%d\n",p,*p);
}

void func1(int **p)
{
    *p=&a;
    printf("%p\n%d\n",*p,**p);
}

int main()
{
    int x=10;
    int *p=&x;
    printf("使用func前%p\n%d\n",p,*p);
    func(p);
    printf("调用func后%p\n%d\n",p,*p);

    printf("使用func1前%p\n%d\n",p,*p);
    func1(&p);
    printf("调用func后%p\n%d\n",p,*p);



    return 0;
}