#include <bits/posix2_lim.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>



void error_sys(const char *s)
{
    perror(s);
    exit(1);
}

int main()
{
    int listenfd,clindfd,ret,count;
    char buf[BUFSIZ];
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    if(listenfd==-1)error_sys("socket()");
    struct sockaddr_in server_addr,client_addr;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(4500);
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    ret=bind(listenfd,(void *)&server_addr,sizeof(server_addr));
    if(ret==-1)error_sys("bind()"); 
    listen(listenfd, 5);
    socklen_t clinet_addr_size=sizeof(client_addr);
    while(1)
    {
        clindfd=accept(listenfd,(struct sockaddr *)&client_addr, &clinet_addr_size);
        read(clindfd, buf, BUFSIZ);
        count=sizeof(buf);
        for(int i=0;i<count;i++) buf[i]=toupper(buf[i]);
        write(clindfd, buf, BUFSIZ);
        inet_ntop(AF_INET,(void *)&client_addr.sin_addr,buf,BUFSIZ);
        printf("clint ip %s and port %d\n",buf,client_addr.sin_port);
        close(clindfd);
    }


    close(listenfd);
    exit(0);

}