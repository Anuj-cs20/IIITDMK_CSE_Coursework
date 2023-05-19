// Producer Consumer Problem
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define THREAD_NUM 2
#define BUFFER_SIZE 10

pthread_mutex_t mutexBuffer;
sem_t semEmpty, semFull;

int buffer[BUFFER_SIZE];
int count = 0;

void *producer(void *args)
{
    while (1)
    {
        // Produce
        int p = rand() % 100;

        // Add to buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        buffer[count] = p;
        count++;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

void *consumer(void *args)
{
    while (1)
    {
        // removing from buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        int c = buffer[count - 1];
        count--;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);

        // Consume
        printf("\nGot %d", c);
    }
}

int main()
{
    srand(time(NULL));
    pthread_t thread[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer, NULL);
    sem_init(&semEmpty, 0, BUFFER_SIZE);
    sem_init(&semFull, 0, 0);
    for (int i = 0; i < THREAD_NUM; i++)
    {
        if (i % 2)
        {
            if (pthread_create(&thread[i], NULL, &producer, NULL) != 0)
            {
                perror("Unable to create producer thread");
                return 1;
            }
        }
        else
        {
            if (pthread_create(&thread[i], NULL, &consumer, NULL) != 0)
            {
                perror("Unable to create consumer thread");
                return 1;
            }
        }
    }

    for (int i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(thread[i], NULL) != 0)
        {
            perror("Unable to join the thread");
            return 1;
        }
    }
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}