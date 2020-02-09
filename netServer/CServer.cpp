#include <sys/socket.h>

#ifndef __C_SERVER_H
#define __C_SERVER_H
#define PORT 8080 

class CServer
{
private:
    int __domain;
    __socket_type __type = SOCK_STREAM;
    int __protocol = 0;
    struct sockaddr *__addr;
    socklen_t *__addrlen;

protected:
    int _socket(int domain, __socket_type type, int protocol)
    {
        socket(domain, type, protocol);
    }; // socket descriptor like a file-handler
    int _setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
    int _bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    int _listen(int sockfd, int backlog);
    int _accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

public:
    void start()
    {
        // socket creation
        int sockfd = _socket(__domain, __type, __protocol);
        int new_socket = accept(sockfd, __addr, __addrlen);
    }
};
#endif

int main(){
    CServer server;
    server.start();
    return 0;
}