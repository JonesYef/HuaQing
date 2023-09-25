#include "../../unp.h"
#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>



/*
构建一个多进程的服务器
*/

void catch_child(int sig)
{
    while( waitpid(0, NULL, WNOHANG) >0);
    return;
}


int main()
{
    int listenfd,clientfd,ret;
    socklen_t cli_addr_len;
    pid_t pid;
    time_t tm;
    time(&tm);
    char buf[BUFSIZ];
    struct sockaddr_in  ser_addr,cli_addr;
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_port=htons(PORT);
    ser_addr.sin_family=AF_INET;
    inet_pton(AF_INET, ADDR, (void *)&ser_addr.sin_addr);
    listenfd=Socket(AF_INET, SOCK_STREAM, 0);
    Bind(listenfd, (void *)&ser_addr, sizeof(ser_addr));
    Listen(listenfd, BACKLOG);
    cli_addr_len=sizeof(cli_addr);
    while(1)
    {
        clientfd=Accept(listenfd,(void *)&cli_addr,&cli_addr_len);
        pid=fork();
        if(pid==0)
        {
            inet_ntop(AF_INET,(void *)&cli_addr.sin_addr,buf, sizeof(buf));
            printf("%s connectd time is  %s\n",buf,ctime(&tm));
            close(listenfd);
            for(;;)
            {
                ret=read(clientfd, buf,sizeof(buf));
                if(ret==0 || buf[0]=='q') 
                {
                    close(clientfd);
                    printf("disconnected.........\n");
                    exit(0);
                }
                for(int i=0;i<ret;i++) buf[i]=toupper(buf[i]);
                write(clientfd, buf, ret);
            }
        }
        else if(pid>0)
        {
            close(clientfd);
            struct sigaction act;
            sigemptyset(&act.sa_mask);
            act.sa_flags=0;
            act.sa_handler=catch_child;
            sigaction(SIGCHLD,&act,NULL);
        }
        else error_sys("fork()");
    }
    exit(0);
}

