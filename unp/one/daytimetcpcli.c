#include "../unp.h"
#include <cstdio>
#include <stddef.h>

void error_quit(const char * s)
{
    fprintf(stderr,"%s,and error is %d\n",s,errno);
    exit(1);
}


int main(int argc,char **argv)
{
    int sockfd,n,ret;
    char recvline[BUFSIZ+1];
    struct sockaddr_in servaddr;
    if(argc!=2) error_quit("Usage <Ipaddress>");
    sockfd=socket(PF_INET,SOCK_STREAM,0);
    if(sockfd<0) error_quit("socket error");
    bzero(&servaddr, sizeof(struct sockaddr_in));
    servaddr.sin_family=PF_INET;
    ret=inet_pton(PF_INET, argv[1], &servaddr.sin_addr);
    if(ret<=0)error_quit("inet_pton error for argv");
    servaddr.sin_port=htons(PORT);
    ret=connect(sockfd, (void *)&servaddr, sizeof(servaddr));
    if(ret<0) error_quit("connect error");


    while((n=read(sockfd, recvline, BUFSIZ))>0)
    {
        recvline[n]=0;
        if(fputs(recvline, stdout)==EOF) error_quit("fputs error");
    }
    if(n<0)error_quit("read error");
    exit(0);
}

