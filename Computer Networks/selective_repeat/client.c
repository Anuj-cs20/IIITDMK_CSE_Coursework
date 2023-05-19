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

int con()
{
    char k[9];
    int i = 1;
    while (data[i] != '\0')
    {
        k[i - 1] = data[i];
        i++;
    }
    k[i - 1] = '\0';
    i = atoi(k);
    return i;
}

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    int ack;
    char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    // if (setsockopt(server_fd, SOL_SOCKET,
    // 			SO_REUSEADDR | SO_REUSEPORT, &opt,
    // 			sizeof(opt))) {
    // 	perror("setsockopt");
    // 	exit(EXIT_FAILURE);
    // }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    int n = 16, sw = 4, c = 0;
    int ackarr[sw];
    int ptr1 = 0;
    for (int i = 1; i <= sw && i <= n; i++)
    {
        alpha9(i);
        send(new_socket, data, sizeof(data), 0);
        printf("\nSending Frame: %d", i);
        ptr1++;
    }
    while (1)
    {
        recv(new_socket, data, sizeof(data), 0);
        int ack = atoi(data);
        if (data[0] == 'N')
        {
            int nack = con();
            printf("\nReceived -Acknowledgement frame: %d", nack);
            alpha9(nack);
            send(new_socket, data, sizeof(data), 0);
            printf("\nSending Frame: %d", nack);
        }
        else
        {
            printf("\nReceived Acknowledgement frame: %d", ack);
            c++;
            if (ptr1 <= n)
            {
                alpha9(ptr1);
                send(new_socket, data, sizeof(data), 0);
                printf("\nSending Frame: %d", ptr1);
                ptr1++;
            }
            else
            {
                // printf("\n%d\n", c);
                while (c != n + 1)
                {
                    recv(new_socket, data, sizeof(data), 0);
                    int ack = atoi(data);
                    if (data[0] == 'N')
                    {
                        int nack = con();
                        printf("\nReceived -Acknowledgement frame: %d", nack);
                        alpha9(nack);
                        send(new_socket, data, sizeof(data), 0);
                        printf("\nSending Frame: %d", nack);
                    }
                    else
                    {
                        printf("\nReceived Acknowledgement frame: %d", ack);
                        c++;
                    }
                }

                alpha9(0);
                send(new_socket, data, sizeof(data), 0);
                break;
            }
        }
    }

    // closing the connected socket
    // close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}
