#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int global[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i = 0, j = 0, s[] = {0, 0};

void *thread_fn(void *arg)
{
    for (; i < 5 * (j + 1); i++)
    {
        s[j] += global[i];
    }
    j++;
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_fn, NULL);
    pthread_join(t1, NULL);
    // sleep(1);
    pthread_create(&t2, NULL, thread_fn, NULL);
    pthread_join(t2, NULL);

    printf("s1: %d\ns2: %d\nsum: %d", s[0], s[1], s[0] + s[1]);

    return 0;
}
