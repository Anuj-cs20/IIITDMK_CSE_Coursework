#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main()
{
    int s_sock;
    char msg[256];
    s_sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server, other;
    server.sin_family = AF_INET;
    server.sin_port = htons(9001);
    server.sin_addr.s_addr = INADDR_ANY;
    socklen_t add;
    bind(s_sock, (struct sockaddr *)&server, sizeof(server));
    add = sizeof(other);
    recvfrom(s_sock, msg, sizeof(msg), 0, (struct sockaddr *)&other, &add);
    printf("server msg:%s", msg);
    return 0;
}