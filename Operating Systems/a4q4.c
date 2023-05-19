#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();
    if (pid > 0)
    {
        wait(NULL);
        pid = fork();
        if (pid > 0) 
        {
            wait(NULL);
            printf("Parent Process: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
        }
        else 
        {
            printf("Child at Level 1: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
            exit(1);
        }
    }
    else 
    {
        pid = fork() && fork();
        if (pid > 0)
        {
            wait(NULL);
            printf("Child at Level 1: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
        }
        else 
        {
            printf("Child at Level 2: My ID is: %d and Parent ID is: %d\n", getpid(), getppid());
            exit(1);
        }
    }
    return 0;
}