// Dynamic Programming : 0/1 Knapsack
// Max Profit and limited weight

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int a, int b)
{
    return (a > b) ? a : b;
}

void findMaxProfit(int *wt, int *val, int n, int kw)
{
    int K[n + 1][kw + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= kw; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                K[i][w] = maxProfit(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    cout << "Printing Table...." << endl;
    cout << "   ";
    for (int w = 0; w < kw + 1; w++)
    {
        cout << w << "  ";
    }
    cout << endl;

    for (int i = 0; i < n + 1; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < kw + 1; j++)
        {
            cout << K[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Max Profit: " << K[n][kw];
}

int main()
{

    int Kw;
    cout << "Enter Weight of Knapsack: ";
    cin >> Kw;

    int n;
    cout << "Number of inputs: ";
    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter weight-" << i + 1 << ": ";
        cin >> a[i];
        cout << "Enter value-" << i + 1 << ": ";
        cin >> b[i];
    }
    cout << endl;

    findMaxProfit(a, b, n, Kw);

    return 0;
}