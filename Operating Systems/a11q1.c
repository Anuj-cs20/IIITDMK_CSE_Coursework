#include <stdio.h>
#define P 4
#define R 3
int main()
{
    int allocation[P][R], maxNeed[P][R], available[2][R];
    int remainingNeed[P][R];
    printf("Enter Allocation Matrix: \n");
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter MAX Need Matrix: \n");
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            scanf("%d", &maxNeed[i][j]);
            remainingNeed[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    printf("Enter Availabitity: \n");
    for (int j = 0; j < R; j++)
    {
        scanf("%d", &available[0][j]);
        available[1][j] = available[0][j];
    }

    int k = 0;
    int additionalRequest[R];
    while (k != 2)
    {
        if (k == 1)
        {
            int p;
            printf("\n\nProcess number: ");
            scanf("%d", &p);
            printf("Enter Additional request: \n");
            for (int j = 0; j < R; j++)
            {
                scanf("%d", &additionalRequest[j]);
                if (available[k][j] >= additionalRequest[j])
                {
                    available[k][j] -= additionalRequest[j];
                    allocation[p][j] += additionalRequest[j];
                    remainingNeed[p][j] -= additionalRequest[j];
                }
                else
                {
                    printf("\nadditional request exceeds availability\n");
                    return 0;
                }
            }
        }

        int status[P];
        for (int i = 0; i < P; i++)
        {
            status[i] = 0;
        }

        int flag1 = 0, flag2 = 0, count = 0;
        do
        {
            // flag1 = 0;
            for (int i = 0; i < P; i++)
            {
                if (status[i] == 0)
                {
                    flag2 = 0;
                    for (int j = 0; j < R; j++)
                    {
                        if (remainingNeed[i][j] <= available[k][j])
                        {
                            flag2++;
                        }
                    }
                    if (flag2 == R)
                    {
                        for (int j = 0; j < R; j++)
                        {
                            available[k][j] += allocation[i][j];
                        }
                        flag1 = 1;
                        count++;
                        status[i] = count;
                    }
                }
            }
        } while (flag1 && count != P);

        if (flag1)
        {
            printf("\nSAFE\n");
            // printf("P1\tP2\tP3\tP4\tP5\n");
            for (int i = 0; i < P; i++)
            {
                printf("P%d\t", i);
            }
            printf("\n");
            for (int i = 0; i < P; i++)
            {
                printf("%d\t", status[i]);
            }
        }
        else
        {
            printf("\nUNSAFE");
        }
        k++;
    }

    return 0;
}