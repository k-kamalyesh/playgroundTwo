#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

#ifndef __C_CLIENT_H
#define __C_CLIENT_H
#define PORT 8080

using namespace std;

class CClient
{
private:
    int __sock = 0, __valread, __connection;
    struct sockaddr_in __serv_addr;
    char *__hello = "Hello from client";
    char __buffer[1024 * 10] = {0};
	bool __overwriteContinueLoop = true;

    int _inet_pton(int af, const char *__restrict cp, void *__restrict buf)
    {
        return inet_pton(af, cp, buf);
    };
    int _socket(int domain, int type, int protocol)
    {
        socket(domain, type, protocol);
    }
    int _send(int sock, const char *hello, int flags)
    {
        send(sock, hello, strlen(hello), flags);
    }
    ssize_t _read(int sock, void *buffer, size_t size)
    {
        return read(sock, buffer, size);
    }

protected:
    void createSocket()
    {
        try
        {
            __sock = _socket(AF_INET, SOCK_STREAM, 0);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    void resolveAddress()
    {
        __serv_addr.sin_family = AF_INET;
        __serv_addr.sin_port = htons(PORT);

        // Convert IPv4 and IPv6 addresses from text to binary form
        try
        {
            inet_pton(AF_INET, "127.0.0.1", &__serv_addr.sin_addr);
        }
        catch (const std::exception &e)
        {
            printf("\nInvalid address/ Address not supported \n");
            std::cerr << e.what() << '\n';
        }
    }
    void bindConnection()
    {
        try
        {
            __connection = connect(__sock, (struct sockaddr *)&__serv_addr, sizeof(__serv_addr));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    void loop()
    {
        std::string message;
        bool continueLoop = true;
        _send(__sock, __hello, 0);
        do
        {
            std::cin >> message;
            const char *msg = message.c_str();
            _send(__sock, msg, 0);
            printf("message sent\n");
            if (message.length() == 1 && message.at(0) == 'q' || message.at(0) == 'Q')
            {
                continueLoop = false;
            }
            else
            {
                __valread = _read(__sock, __buffer, sizeof(__buffer));
                printf("%s\n", __buffer);
            }
        } while (continueLoop && __overwriteContinueLoop);
    }

public:
    void init()
    {
        createSocket();
        resolveAddress();
        bindConnection();
    }
    void start()
    {
        loop();
    }
    void stop(){
        // need to invoke using threads?
        // multithreading!?
        __overwriteContinueLoop = false;
    }
};
#endif

int main()
{
    CClient client;
    client.init();
    client.start();
    return 0;
}