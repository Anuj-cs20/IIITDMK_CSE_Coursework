#include <bits/stdc++.h>
using namespace std;

const int N = 520;
const int INF = 1e9 + 10;

vector<vector<int> > dist(N, vector<int>(N));

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "#"
                     << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
int main()
{
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist.size(); j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    int n, v;
    cout << "enter no of nodes and no of edges : ";
    cin >> n >> v;
    for (int i = 0; i < v; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = dist[y][x] = wt;
    }
    string x = "";
    for (int k = 1; k <= n - 1; k++)
    {
        cout << "level : " << k << " \n";
        for (int i = 1; i <= n; i++)
        {
            cout << "----------------------------------------------------\n";
            cout << "from\t\tto\t\tdist\t\tthrough\t\t\n";
            for (int j = 1; j <= n; j++)
            {

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

                if (dist[i][j] == dist[i][k] + dist[k][j])
                {
                    if (i != k)
                        x = k + 64;
                    else
                        x = j + 64;
                }
                else
                {
                    if (i == j)
                    {
                        x = i + 64;
                    }
                    else
                    {
                        x = j + 64;
                    }
                }
                string flag = "";
                if (dist[i][j] == INF)
                {
                    flag = "#";
                    x = "-";
                }
                else
                {
                    flag = to_string(dist[i][j]);
                }
                cout << i << "\t\t" << j << "\t\t" << flag << "\t\t" << x << "\t\t\n";
            }
            cout << "----------------------------------------------------------\n";
            cout << "\n";
            cout << "\n";
        }
    }
    print(n);
}