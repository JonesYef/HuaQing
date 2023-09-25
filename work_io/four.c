#include<stdio.h>
#include<stdlib.h>


/*
逆序操作一个文件
*/

int main(int argc,char **argv)
{
    if(argc<3){
        fprintf(stderr, "%s:Usge <src> <des>\n",__FILE__);
        exit(-1);
    }   
    FILE * fpr,*fpw;
    int ch;
    fpr=fopen(argv[1],"r");
    fpw=fopen(argv[2],"w");
    if(!fpr||!fpw) {
        perror("fopen()");
        exit(-1);
    }
    fseek(fpr,-1,SEEK_END);
    int count=ftell(fpr);
    //printf("ftell is %d\n",count);
    for(int i=0;i<count+1;i++)
    {
        ch=fgetc(fpr);
        fputc(ch, fpw);
        fseek(fpr,-2,SEEK_CUR);
    }
    fclose(fpr);
    fclose(fpw);

    return 0;
}