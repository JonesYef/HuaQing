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


int main(int argc,char **argv)
{
    if(argc<3){
        fprintf(stderr,"Usge:<port> <IP>\n");
        exit(1);
    }
    int sockfd,ret;
    char buf[BUFSIZ];
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1) error_sys("socket()");
    struct sockaddr_in server_addr;
    
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(atoi(argv[1]));
    inet_pton(sockfd,argv[2],&server_addr.sin_addr);
    ret=connect(sockfd,(void *)&server_addr,sizeof(server_addr));
    if(ret==-1)error_sys("connect()");
    for(;;){
        printf("请输入小写字母:\n");
        ret=read(0,buf,BUFSIZ);
        write(sockfd, buf,ret);
        read(sockfd,buf,BUFSIZ);
        fputs(buf,stdout);
    }
    close(sockfd);
    return 0;
}   