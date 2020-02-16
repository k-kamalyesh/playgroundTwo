#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>

#ifndef __C_SERVER_H
#define __C_SERVER_H
#define PORT 8080

using namespace std;

class CServer
{
private:
	int __domain;
	__socket_type __type = SOCK_STREAM;
	int __protocol = 0;
	struct sockaddr *__addr;
	//socklen_t *__addrlen;
	int __server_fd, __new_socket, __valread;
	struct sockaddr_in __address;
	int __opt = 0;
	int __addrlen = sizeof(__address);
	char __buffer[1024 * 10] = {0};
	char *__hello = "Hello from server";
	bool __overwriteContinueLoop = true;

	int _socket(int domain, __socket_type type, int protocol)
	{
		return socket(domain, type, protocol);
	};
	int _setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen)
	{
		setsockopt(sockfd, level, optname, optval, optlen);
	};
	int _bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
	{
		return bind(sockfd, addr, addrlen);
	};
	int _listen(int sockfd, int backlog)
	{
		return listen(sockfd, backlog);
	};
	int _accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
	{
		return accept(sockfd, addr, addrlen);
	};
	int _read(int new_socket, char *buffer, int size)
	{
		return read(new_socket, buffer, size);
	}
	int _send(int new_socket, const void *hello, size_t helloLength, int flags)
	{
		return send(new_socket, hello, helloLength, flags);
	}

protected:
	void createSocket()
	{
		// Creating socket file descriptor
		if ((__server_fd = _socket(AF_INET, SOCK_STREAM, 0)) == 0)
		{
			perror("socket failed");
			exit(EXIT_FAILURE);
		}
	}
	void bindPort()
	{
		// Forcefully attaching socket to the port 8080
		if (_setsockopt(__server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &__opt, sizeof(__opt)))
		{
			perror("setsockopt");
			exit(EXIT_FAILURE);
		}
		__address.sin_family = AF_INET;
		__address.sin_addr.s_addr = INADDR_ANY;
		__address.sin_port = htons(PORT);

		if (_bind(__server_fd, (struct sockaddr *)&__address, sizeof(__address)) < 0)
		{
			perror("bind failed");
			exit(EXIT_FAILURE);
		}
		if (_listen(__server_fd, 3) < 0)
		{
			perror("listen");
			exit(EXIT_FAILURE);
		}
		if ((__new_socket = _accept(__server_fd, (struct sockaddr *)&__address, (socklen_t *)&__addrlen)) < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
	}
	void loop()
	{
		bool continueLoop = true;
		do
		{
			memset(__buffer, 0, sizeof(__buffer));
			__valread = _read(__new_socket, __buffer, 1024 * 10);
			std::cout << __buffer << std::endl;
			std::string msg = std::string(__buffer);
			if (msg.length() == 1 && msg.at(0) == 'q' || msg.at(0) == 'Q')
			{
				continueLoop = false;
			}
			else
			{
				_send(__new_socket, __hello, strlen(__hello), 0);
				printf("message sent\n");
			}
			sleep(0);
		} while (continueLoop && __overwriteContinueLoop);
	}

public:
	void init()
	{
		createSocket();
		bindPort();
	}
	void start()
	{
		// socket creation
		__overwriteContinueLoop = true;
		loop();
	}
	void pause()
	{
	}
	void stop(){
		__overwriteContinueLoop = false;
	}
};
#endif

int main()
{
	CServer server;
	server.init();
	server.start();
	return 0;
}
