#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


/*
使用单个输入输出函数来实现文件cp功能
fgetc
fputc
*/
#define MAXSIZE 1024

int main(int argc,char ** argv)
{
    if(argc<3){
        fprintf(stderr, "%s:Usge <src> <des>\n",__FILE__);
        exit(-1);
    }
    FILE * fpr,*fpw;
    char buf[MAXSIZE];
    size_t ret;
    fpr=fopen(argv[1],"r");
    fpw=fopen(argv[2], "w");
    if( !fpr || !fpw) {
        perror("fopen ");
        exit(-1);
    }
    while((ret=fread(buf, sizeof(char), 1, fpr))!=0) fwrite(buf, sizeof(char), 1, fpw);
    fclose(fpr);
    fclose(fpw);
    return 0;
}