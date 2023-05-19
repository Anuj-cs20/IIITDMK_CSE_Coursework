#include <bits/stdc++.h>
using namespace std;
int V;

void impDFS(bool **gr, int *vi, int u, int c)
{
    vi[u] = c;

    for (size_t v = 0; v < V; v++)
    {
        if (gr[u][v] && vi[v] == c)
        {
            cout << "Not Bipartite" << endl;
            exit(0);
        }

        if (gr[u][v] && vi[v] == -1)
        {
            impDFS(gr, vi, v, 1 - c);
        }
    }
}

int main()
{
    cout << "Enter Number of Vertices in a graph: ";
    cin >> V;

    // 2D Matrix
    bool **G;
    G = new bool *[V];
    for (size_t i = 0; i < V; i++)
    {
        G[i] = new bool[V];
    }

    int e = 0;
    cout << "\nEnter 1 if edge exists or 0 for does't exists" << endl;
    for (size_t i = 0; i < V; i++)
    {
        G[i][i] = 0;
        for (size_t j = i + 1; j < V; j++)
        {
            cout << " edge(" << i + 1 << "," << j + 1 << "): ";
            cin >> G[i][j];
            G[j][i] = G[i][j];
            if (G[i][j])
            {
                ++e;
            }
        }
    }

    cout << "\nPrinting the Matrix" << endl;
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int *vis = new int[V];

    for (size_t i = 0; i < V; i++)
    {
        vis[i] = -1;
    }

    impDFS(G, vis, 0, 1);

    cout << "Bipartite" << endl;
    return 0;
}