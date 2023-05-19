#include <stdio.h>
#define INF 99999

void printMatrix(int n, int dist[][n], int k)
{
    printf("\nMatrix A^%d\n", k);
    if (k == n - 1)
    {
        printf("Matrix with shortest distances between every pair of vertices\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("\t%d", i + 1);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d", i + 1);
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("\t%s", "INF");
            }
            else
            {
                printf("\t%d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void fW(int n, int g[][n])
{
    int sd[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sd[i][j] = g[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sd[i][k] + sd[k][j] < sd[i][j] && sd[i][k] != INF && sd[k][j] != INF)
                {
                    sd[i][j] = sd[i][k] + sd[k][j];
                }
            }
        }
        printMatrix(n, sd, k);
    }
}

int main()
{
    int n;
    printf("Enter Number of nodes in the graph: ");
    scanf("%d", &n);
    int g[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int res;
            printf("Does edge exists btw (%d,%d): ", i + 1, j + 1);
            scanf("%d", &res);
            if (res)
            {
                printf("Enter weight of the edge: ");
                scanf("%d", &g[i][j]);
            }
            else
            {
                g[i][j] = INF;
            }
        }
        g[i][i] = 0;
    }

    fW(n, g);
    return 0;
}
