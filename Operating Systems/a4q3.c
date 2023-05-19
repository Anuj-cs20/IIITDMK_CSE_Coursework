#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int pid = fork();

    if (pid > 0)
    {
        printf("Indian Institute of Information Technology, Design & Manufacturing Kancheepuram");
        printf("\nParent Process\npid: %d, parent pid: %d, child pid: %d", getpid(), getppid(), pid);
    }
    else
    {
        printf("\nChild Process\npid: %d, parent pid: %d, child pid: %d", getpid(), getppid(), pid);
        execlp("./dummy", "", NULL);
    }

    return 0;
}