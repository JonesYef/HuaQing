#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/*
使用单行输入输出函数来实现文件cp功能
fgets
fputs
*/
#define MAXSIZE 1024

int main(int argc,char **argv)
{
    if(argc<3){
        fprintf(stderr, "%s:Usge <src> <des>\n",__FILE__);
        exit(-1);
    }
    FILE * fp1,*fp2;
    char buf[MAXSIZE];
    char *ret;
    fp1=fopen(argv[1], "r");
    fp2=fopen(argv[2], "w");
    if(!fp1 ||!fp2)  {       
        perror("fopen ");
        exit(-1);
    }
    while(1){
        ret=fgets(buf,MAXSIZE,fp1);
        if(ret==NULL)break;
        fputs(buf,fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}