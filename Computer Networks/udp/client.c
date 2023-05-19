#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int c_sock;
    char msg[256] = "i am client";
    c_sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in client, other;
    client.sin_family = AF_INET;
    client.sin_port = htons(9001);
    client.sin_addr.s_addr = INADDR_ANY;
    socklen_t ad;
    ad = sizeof(other);
    sendto(c_sock, msg, sizeof(msg), 0, (struct sockaddr *)&client, sizeof(client));
    printf("client send:%s", msg);
    // close(c_sock);
    return 0;
}