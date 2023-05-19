#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h> // read write and close
#define PORT 3030

int main()
{
    int s_fd, new_sock, vread;
    struct sockaddr_in addr;
    int opt = 1;
    int addrlen = sizeof(addr);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // A file descriptor is an unsigned integer used by a process to identify an open file
    // int socketfd = socket(int domain,int type,int protocal)
    // communication domain AF_INET IPv4
    // communication type TCP
    // protocal for IP 0
    if ((s_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(1);
    }

    // if (setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    // {
    //     perror("setsockopt");
    //     exit(1);
    // }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT); // host to network short

    // int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    // bind function binds the socket to the address 
    // and port number specified in addr(custom data structure)
    if (bind(s_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind failed");
        exit(1);
    }

    // int listen(int sockfd, int backlog);
    // it waits for the client to approach the server to make a connection
    // backlog is number of max connections
    if (listen(s_fd, 3) < 0)
    {
        perror("listen");
        exit(1);
    }

    // int new_socket= accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    // returns new socket desct
    if ((new_sock = accept(s_fd, (struct sockaddr *)&addr, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(1);
    }

    // buffer = 1024 is msg max len
    vread = read(new_sock, buffer, 1024);
    printf("%s\n", buffer);
    send(new_sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    close(new_sock);

    shutdown(s_fd, SHUT_RDWR);
    return 0;
}
