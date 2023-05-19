#include <bits/stdc++.h>
using namespace std;
int V;

bool impDFS(bool **gr, bool *vi, int u, int p)
{
    vi[u] = true;

    for (size_t v = 0; v < V; v++)
    {
        if (gr[u][v] && v != p && vi[v])
        {
            cout << "Graph is cyclic " << endl;
            exit(0);
        }

        if (gr[u][v] && !vi[v])
        {
            impDFS(gr, vi, v, u);
        }
    }

    return 0;
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

    if (e > V)
    {
        cout << "Graph is cyclic" << endl;
    }
    else
    {
        bool *vis = new bool[V];
        bool u = 0, v;

        for (size_t i = 0; i < V; i++)
        {
            if (G[0][i])
            {
                v = i;
                break;
            }
        }

        if (!impDFS(G, vis, u, v))
        {
            cout << "Graph is not cyclic" << endl;
        }
    }

    return 0;
}