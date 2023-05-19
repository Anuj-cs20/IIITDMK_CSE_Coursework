#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();
    int status;
    wait(&status);
    if (pid > 0)
    {
        int psize;
        printf("\nEnter size of the array: ");
        scanf("%d", &psize);

        printf("\nEnter elements of the array: ");
        int *pptr = (int *)malloc(psize * sizeof(int));
        for (int i = 0; i < psize; i++)
        {
            scanf("%d", &pptr[i]);
        }

        printf("\nElements\tAddress\n");
        for (int i = 0; i < psize; i++)
        {
            printf("%d\t%p\n", pptr[i], &pptr[i]);
        }

        for (int i = 0; i < psize; i++)
        {
            for (int j = 0; j < psize - i - 1; j++)
            {
                if (pptr[j] > pptr[j + 1])
                {
                    int tmp = pptr[j];
                    pptr[j] = pptr[j + 1];
                    pptr[j + 1] = tmp;
                }
            }
        }

        printf("\nSorted Array: ");
        for (int i = 0; i < psize; i++)
        {
            printf("%d ", pptr[i]);
        }
    }
    else
    {
        int csize;
        printf("\nEnter size of the array: ");
        scanf("%d", &csize);

        printf("\nEnter elements of the array: ");
        int *cptr = (int *)malloc(csize * sizeof(int));
        for (int i = 0; i < csize; i++)
        {
            scanf("%d", &cptr[i]);
        }

        printf("\nElements\tAddress\n");
        for (int i = 0; i < csize; i++)
        {
            printf("%d\t%p\n", cptr[i], &cptr[i]);
        }

        for (int i = 0; i < csize; i++)
        {
            int tmp = cptr[i];
            cptr[i] = cptr[csize - i - 1];
            cptr[csize - i - 1] = tmp;
        }

        printf("\nReverse Array: ");
        for (int i = 0; i < csize; i++)
        {
            printf("%d ", cptr[i]);
        }
        exit(0);
    }
    return 0;
}