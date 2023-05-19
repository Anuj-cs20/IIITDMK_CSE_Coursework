#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int pipe1[2], pipe2[2];
    int status1, status2;

    status1 = pipe(pipe1);
    if (status1 == -1)
    {
        printf("Unable to create pipe1");
        return 0;
    }

    status2 = pipe(pipe2);
    if (status2 == -1)
    {
        printf("Unable to create pipe1");
        return 0;
    }

    int pid;
    pid = fork();

    if (pid > 0)
    {
        close(pipe1[0]);
        close(pipe2[1]);

        char pstr[20], prstr[20];
        printf("Parent Process\nEnter a String: ");
        scanf("%s", pstr);
        write(pipe1[1], pstr, sizeof(pstr));
        sleep(5);
        read(pipe2[0], prstr, sizeof(prstr));
        printf("\nParent Process\nReverse String is: %s", prstr);
    }
    else
    {
        close(pipe1[1]);
        close(pipe2[0]);

        sleep(2);
        char cstr[20], crstr[20];
        read(pipe1[0], cstr, sizeof(cstr));
        // printf("\nChild Process\nReceived String is: %s", cstr);

        int j = 0;
        for (int i = strlen(cstr) - 1; i >= 0; i--)
        {
            crstr[j] = cstr[i];
            j++;
        }

        write(pipe2[1], crstr, sizeof(crstr));
    }
    return 0;
}