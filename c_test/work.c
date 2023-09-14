/*  1、指出以下代码片段的不妥之处
    structure{
    char itable;
    int num[20];
    char * togs
    }

    名字和关键词粘连在一起
    没有分号
*/

/*
    2、设计一个结构模板，保存一个月份名、一个3个字母的该月份的缩写、该月的天数，以及月份号。

        struct month{
        char * name;
        char o[3];
        };

*/


/*
    3、分析以下结构所占的存储空间大小：
    struct animals{
    char dog;
    unsigned long cat;
    unsigned short pig;
    char fox;
    };
    64位占24字节  32位占12字节
*/


/*
    4、定义一个结构体变量(包括年月日)。计算该日在本年中是第几天？注意闰年问题。


        #include <stdio.h>
        struct date{
            int yeah;
            int month;
            int day;
        };
        void fun(const struct date  *d){
            printf("day is %d\n",30*d->month+d->day);
        }
*/


/*
    5、假设有以下结构：
    struct  gas {
        float  distance; 
        float  gals;
        float  mpg;  // mpg = distance * gals
    };
    a) 设计一个函数，它接受一个struct gas参数。假定传递进来的结构包括distance和gals信息。函数为mpg成员正确计算初值并返回这个完整的结构。
    b)设计一个函数，它接受一个struct gas参数的地址。假定传递进来的结构包括distance和gals信息。函数为mpg成员正确计算初值并把它赋给恰当的成员。


        struct  gas {
            float  distance; 
            float  gals;
            float  mpg;  // mpg = distance * gals
        };

    struct gas Rempg(struct gas  p){
        p.mpg=p.distance*p.gals;
        return p;
    }
    void Re(struct gas *p){
        p->mpg=p->distance*p->gals;
    }



*/


/*
    6、声明一个枚举类型，使用choices作为标记，将枚举常量no、yes和maybe分别设置为0、1和2。

    enum choices{
        no,
        yes,
        maybe
    };

*/


/*
    7、写一个带参数的宏MIN(x, y)，这个宏输入两个参数并返回较小的一个。
    #define MIN(X,Y) (X) < (Y) ? (X) :(Y)
*/


/*
    8、用预处理指令#define 声明一个常数，用以表明1年中有多少秒（忽略闰年问题）。
    #define SEC 365*24*60*60
*/

/*
    9、某头文件中有以下语句，解释其作用：
    #ifndef  SOME_HEADER_H_
    #define SOME_HEADER_H_
    … …
    #endif

    头文件的条件编译,为了防止头文件的重复包含
*/

/*
    10、编写一个程序，若处理器是大端序的则返回0，若处理器是小端序的则返回1。

        bool func(){

        union Un{
        char a;
        unsigned int addr;
        };
        union Un n;
        n.addr=0x12345678;
        if(n.a==0x78) return true;
        return false;
    }

*/

/*
    11、编写一个函数，计算1+2+3+4+…+n的值。

    int func(int n){
        if(n<=0) return 0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=i;
        }
        return sum;
    }

*/

/*
    12、用递归的思想重做第二天的第12题。

    不知道题目什么意思?要递归什么题目?
*/

/*
    13、设有以下说明和定义：
typedef union {long i; int k[5]; char c;} DATE;
struct data { int cat; DATE cow; double dog;} too;
DATE max;
则语句
printf("%d",sizeof(struct data)+sizeof(max));的执行结果是？

结果为:64,其中DATE中因为int k[5]存在最大的值为20,但为了long形偏移4字节;
而在data中最大字节为8字节.即为8+24+8=40
*/


/*
    14、编写一个transform()函数，它接受4个参数：包含double类型数据的源数组名，double类型的目标数组名，
    表示数组元素个数的int变量以及一个函数名(或者等价的指向函数的指针)。
    transform()函数把指定的函数作用于源数组的每个元素，并将返回值放到目标数组中。例如：transform(source,  target,  100,  sin);



    #include <string.h>
    void transform(double s_arr[],double t_arr[],int n,void * memcpy(void *, const void *, unsigned long))
    {
        memcpy(t_arr,s_arr,n);
    }   

*/


/*
    15、下面函数实现数组元素的逆转，请填写空白处使其完整。
    
#include <stdio.h>
void  recur(int  a[ ],  int  k)
{
    int  tmp;
    if( &a[0]<&a[k-1])
    {
        recur( a+1, k-2);
        tmp = a[0];
        a[0] = a[k-1];
        a[k-1] = tmp;
    }
}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    recur(arr, 6);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

*/

