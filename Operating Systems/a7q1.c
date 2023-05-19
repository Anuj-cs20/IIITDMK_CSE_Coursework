#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int global = 100;

void *thread_fn(void *l)
{
    int *num = (int *)l;
    (*num)++;
    global++;
    printf("\n\nThread ID: %ld", pthread_self());
    printf("\nLocal variable address: %p, Local variable value: %d", num, *num);
    printf("\nGlobal variable address: %p, Global variable value: %d", &global, global);
    pthread_exit(NULL);
}

int main()
{
    int pid;
    pid = fork();
    int status;
    wait(&status);
    if (pid == 0)
    {
        int clocal = 1;
        pthread_t c1, c2;
        printf("\n\nChild Process:");
        printf("\nProcess Id: %d", getpid());
        pthread_create(&c1, NULL, thread_fn, (void *)&clocal);
        pthread_create(&c2, NULL, thread_fn, (void *)&clocal);
        pthread_join(c1, NULL);
        pthread_join(c2, NULL);
        exit(0);
    }
    else
    {
        int plocal = 2;
        pthread_t p1, p2;
        printf("\n\nParent Process:");
        printf("\nProcess Id: %d", getpid());
        pthread_create(&p1, NULL, thread_fn, (void *)&plocal);
        pthread_create(&p2, NULL, thread_fn, (void *)&plocal);
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
    }

    return 0;
}