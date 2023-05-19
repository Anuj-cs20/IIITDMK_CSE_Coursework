// DP for Matrix Chain Multiplication
// Using Tabulation

#include <bits/stdc++.h>
using namespace std;

int minCost(int a, int b)
{
    return a > b ? b : a;
}

int findMinCost(int **t, int *m, int n)
{
    int j, k;
    // x is chain length.
    for (int x = 2; x < n; x++)
    {
        for (int i = 1; i < n - x + 1; i++)
        {
            j = i + x - 1;                  
            t[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                t[i][j] = minCost(t[i][j], t[i][k] + t[k + 1][j] + m[i - 1] * m[k] * m[j]);
            }
        }
    }

    return t[1][n - 1];
}

int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter Array Elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Making 2D array of order nxn
    //table to store and reuse Minimum Cost
    // m[i][j] = arr[i]xarr[i+1]....arr[j]

    int **m;
    m = new int *[size];

    for (int i = 0; i < size; i++)
    {
        m[i] = new int[size];
    }

    //multiplication is zero if only one matrix
    for (int i = 1; i < size; i++)
    {
        m[i][i] = 0;
    }

    cout << "Minimum number of Multiplications required are: " << findMinCost(m, arr, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            m[j][i] = -1;
        }
    }

    cout << "\nPrinting Table...." << endl;
    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}