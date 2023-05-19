// DP for Matrix Chain Multiplication
// Using Memoization

#include <bits/stdc++.h>
using namespace std;

int minCost(int a, int b)
{
    return a > b ? b : a;
}

int findMinCost(int **dp, int *p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
    {
        dp[i][j] = minCost(dp[i][j], findMinCost(dp, p, i, k) + findMinCost(dp, p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }

    return dp[i][j];
}

int main()
{
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Making 2D array of order nxn
    int **d;
    d = new int *[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = new int[n];
    }

    // assign all blockes with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = -1;
        }
    }

    // Finding Minimum Cost
    cout << "Minimum number of Multiplications required are: " << findMinCost(d, arr, 1, n - 1);

    return 0;
}