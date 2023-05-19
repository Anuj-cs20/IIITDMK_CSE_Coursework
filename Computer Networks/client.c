#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 3030

int main()
{
    int vread, c_fd, s = 0;
    struct sockaddr_in s_adr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    s_adr.sin_family = AF_INET;
    s_adr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &s_adr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    if ((c_fd = connect(s, (struct sockaddr *)&s_adr, sizeof(s_adr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(s, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    vread = read(s, buffer, 1024);
    printf("%s\n", buffer);

    close(c_fd);
    return 0;
}
