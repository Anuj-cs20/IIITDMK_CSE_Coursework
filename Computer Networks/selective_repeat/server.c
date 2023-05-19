#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>
#define PORT 8080

char data[20];
char data1[20];

void alpha9(int z)
{
    int k, i = 0, j, g;
    k = z;
    while (k > 0)
    {
        i++;
        k = k / 10;
    }
    g = i;
    i--;
    while (z > 0)
    {
        k = z % 10;
        data[i] = k + 48;
        i--;
        z = z / 10;
    }
    data[g] = '\0';
}

void alp(int z)
{
    int k, i = 1, j, g;
    k = z;
    data1[0] = 'N';
    while (k > 0)
    {
        i++;
        k = k / 10;
    }
    g = i;
    i--;
    while (z > 0)
    {
        k = z % 10;
        data1[i] = k + 48;
        i--;
        z = z / 10;
    }
    data1[g] = '\0';
}

int main(int argc, char const *argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((client_fd = connect(sock, (struct sockaddr *)&serv_addr,
                             sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    int p, sw = 4, k = 0;
    while (1)
    {
        recv(sock, data, sizeof(data), 0);
        p = atoi(data);

        if (p == 0)
        {
            break;
        }

        if (rand() % 2) // frame not received
        {
            printf("\n\nReceived frame %d", p);
            alpha9(p + 1);
            send(sock, data, sizeof(data), 0);
        }
        else
        {
            printf("\n\nNack for frame : %d", p);
            alp(p);
            send(sock, data1, sizeof(data1), 0);
        }
    }

    // closing the connected socket
    // close(client_fd);
    return 0;
}