#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int minDistance(int n, int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int n, int graph[n][n], int src)
{
    int dist[n];
    bool sptSet[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[src] = 0;

    for (int c = 0; c < n - 1; c++)
    {
        int u = minDistance(n, dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nRouter %d\t Distance to source\n", src + 1);
    for (int i = 0; i < n; i++)
    {
        printf("to %d \t\t %d \n", i + 1, dist[i]);
    }
}

int main()
{
    int n;
    printf("Enter Number of nodes in the graph: ");
    scanf("%d", &n);
    printf("\nEnter edges weight data: \n");
    int g[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        dijkstra(n, g, i);
    }

    return 0;
}

// 0 3 0 5
// 2 0 0 4
// 0 1 0 0
// 0 0 2 0