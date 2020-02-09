#include <sys/socket.h>
#include <netinet/in.h>

#ifndef __C_CLIENT_H
#define __C_CLIENT_H
#define PORT 8080 

class CClient
{
private:
    int __sockfd;
    socklen_t __addrlen;
    const struct sockaddr *__addr;

protected:
    int _connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
    {
        connect(sockfd, addr, addrlen);
    };

public:
    void start()
    {
        int connection = _connect(__sockfd, __addr, __addrlen);
    }
};
#endif


int main(){
    CClient client;
    client.start();
    return 0;
}