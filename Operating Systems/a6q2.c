#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid, cpid;
    int pipe1[2], pipe2[2];
    int status1, status2;

    char str1[20];
    printf("\n\nParent Process\nEnter String: ");
    scanf("%s", str1);

    char str2[20];
    printf("\n\nGrand Child Process\nEnter String: ");
    scanf("%s", str2);

    status1 = pipe(pipe1);
    if (status1 == -1)
    {
        printf("Error in pipe");
        return 0;
    }
    status2 = pipe(pipe2);
    if (status2 == -1)
    {
        printf("Error in pipe");
        return 0;
    }

    pid = fork();
    if (pid == 0)
    {
        cpid = fork();
        if (cpid == 0)
        {
            // grand child
            close(pipe2[0]);
            printf("\nGrand Child Process id: %d", getpid());
            write(pipe2[1], str2, sizeof(str2));
        }
        else
        {
            // child
            close(pipe1[1]);
            close(pipe2[1]);

            printf("\nChild Process id: %d", getpid());
            char pstr[20], gstr[20];
            read(pipe1[0], pstr, sizeof(pstr));
            read(pipe2[0], gstr, sizeof(gstr));

            printf("\nString lengths difference: %d", abs(strlen(pstr) - strlen(gstr)));
        }
    }
    else
    {
        // parent
        close(pipe1[0]);
        printf("\nParent Process id: %d", getpid());
        write(pipe1[1], str1, sizeof(str1));
    }
    return 0;
}