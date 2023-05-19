#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int M1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int M2[3][3] = {11, 12, 13, 14, 15, 16, 17, 18, 19};

int A[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int S[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int M[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void *thread_fn(void *arg)
{
    int x;
    x = (int)arg;

    if (x == 0)
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                A[i][j] = M1[i][j] + M2[i][j];
            }
        }
    }

    if (x == 1)
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                S[i][j] = M1[i][j] - M2[i][j];
            }
        }
    }

    if (x == 2)
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                for (size_t k = 0; k < 3; k++)
                {
                    M[i][j] += M1[i][k] * M2[k][j];
                }
            }
        }
    }

    pthread_exit(NULL);
}

int main()
{
    printf("\nMatrix M1: \n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d\t", M1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix M2: \n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d\t", M2[i][j]);
        }
        printf("\n");
    }

    pthread_t a;
    pthread_create(&a, NULL, thread_fn, (void *)0);
    pthread_join(a, NULL);

    printf("\nAddition of Matrix M1 and M2: \n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    pthread_t s;
    pthread_create(&s, NULL, thread_fn, (void *)1);
    pthread_join(s, NULL);

    printf("\nSubtraction of Matrix M1 and M2: \n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d\t", S[i][j]);
        }
        printf("\n");
    }

    pthread_t m;
    pthread_create(&m, NULL, thread_fn, (void *)2);
    pthread_join(m, NULL);

    printf("\nMultiplication of Matrix M1 and M2: \n");
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}