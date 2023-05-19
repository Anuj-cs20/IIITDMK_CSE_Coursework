#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

// SPIN LOCK
// int count = 0;
// void *thread_fn(void *arg){
//     char *st = (char *)arg;

//     printf("\nThread-%c id: %ld", *st, pthread_self());

//     printf("\nStatement %c1", *st);
//     count++;

//     while(count != 2){

//     }

//     printf("\nThread-%c id: %ld", *st, pthread_self());

//     printf("\nStatement %c2", *st);

//     pthread_exit(NULL);
// }

// Semaphore
sem_t m1, m2;
void *thread_fn1()
{
    sem_wait(&m1);
    printf("\nStatement A1");
    sem_post(&m2);

    sem_wait(&m1);
    printf("\nStatement A2");
    sem_post(&m2);

    pthread_exit(NULL);
}

void *thread_fn2()
{
    sem_wait(&m2);
    printf("\nStatement B1");
    sem_post(&m1);

    sem_wait(&m2);
    printf("\nStatement B2");
    sem_post(&m1);

    pthread_exit(NULL);
}

int main()
{
    sem_init(&m1, 0, 1);
    sem_init(&m2, 0, 1);

    pthread_t A, B;
    pthread_create(&A, NULL, &thread_fn1, NULL);
    pthread_create(&B, NULL, &thread_fn2, NULL);

    pthread_join(A, NULL);
    pthread_join(B, NULL);

    sem_destroy(&m1);
    sem_destroy(&m2);
    return 0;
}