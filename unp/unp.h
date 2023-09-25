#ifndef __UNP_H_
#define __UNP_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>


#define PORT 4500
#define ADDR "192.168.10.102"
#define BACKLOG 10

void error_sys(const char * s);

int Socket(int domain, int type, int protocol);

int Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);

int Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);




#endif