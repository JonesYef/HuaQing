#include "unp.h"
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <sys/socket.h>


void error_sys(const char * s)
{   
    perror(s);
    exit(1);
}

int Socket(int domain, int type, int protocol)
{
    int sockfd;
    sockfd=socket(domain,type,protocol);
    if(sockfd==-1) error_sys("Socket()");
    return sockfd;
}
int Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
    int ret;
    ret=bind(sockfd,addr, addrlen);
    if(ret==-1)error_sys("Bind()");
    return ret;
}

int Listen(int sockfd, int backlog)
{
    int ret;
    ret=listen(sockfd,backlog);
    if(ret==-1)error_sys("Listen()");
    return ret;
}


int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int clintfd;
    clintfd=accept(sockfd, addr,  addrlen);
    if(clintfd==-1 )
    {
        if(errno==EINTR) return clintfd;
        error_sys("Accept()");
    }
    return clintfd;
}

