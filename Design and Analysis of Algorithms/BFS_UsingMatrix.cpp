// Implementing BFS on Undirected Graph

#include <bits/stdc++.h>
using namespace std;
int V;
queue<int> qu;

void impBFS(bool **gr, bool *vi, int u)
{
    for (int v = 0; v < V; v++)
    {
        if (gr[u][v] && !vi[v])
        {
            vi[v] = true;
            cout << v + 1 << " ";
            qu.push(v);
        }
    }
    qu.pop();

    if (qu.size())
    {
        impBFS(gr, vi, qu.front());
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

    cout << "\nEnter 1 if edge exists or 0 for does't exists" << endl;
    for (size_t i = 0; i < V; i++)
    {
        G[i][i] = 0;
        for (size_t j = i + 1; j < V; j++)
        {
            cout << " edge(" << i + 1 << "," << j + 1 << "): ";
            cin >> G[i][j];
            G[j][i] = G[i][j];
        }
    }

    cout << "BFS is implemented on 1st vertex of the Graph" << endl;
    bool *vis = new bool[V];
    vis[0] = true;
    cout << 1 << " ";
    qu.push(0);
    impBFS(G, vis, 0);

    return 0;
}