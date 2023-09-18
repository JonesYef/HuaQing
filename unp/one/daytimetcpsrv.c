#include "../unp.h"
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>


void error_quit(const char * s)
{
    fprintf(stderr,"%s,and error is %d\n",s,errno);
    exit(1);
}


int main(int argc,char ** argv)
{
    int listenfd,connfd,ret;
    struct sockaddr_in servaddr;
    char buf[MAXSIZE];
    time_t ticks;
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    if(listenfd<0) error_quit("socket error");
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(HOST);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    ret=bind(listenfd, (void *)&servaddr, sizeof(servaddr));
    if(ret<0) error_quit("bind error");
    listen(listenfd, 5);
    while(1)
    {
        connfd=accept(listenfd, NULL, NULL);
        ticks=time(NULL);
        snprintf(buf, sizeof(buf), "%.24s\r\n",ctime(&ticks));
        fputs("client is connected \n", stdout);
        write(connfd, buf, strlen(buf));
        close(connfd);
    }


}



