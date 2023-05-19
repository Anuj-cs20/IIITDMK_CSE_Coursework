//Team : P14

// Greedy Strategy for  Optimal Binary Search tree

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findMaxfreq(int *f, int j, int k)
{
    int max = INT_MIN;
    int max_ind;
    for (int i = j; i <= k; i++)
    {
        if (max < f[i])
        {
            max = f[i];
            max_ind = i;
        }
    }

    return max_ind;
}

int cost = 0;
int N;

void findMinCost(int *f, int i, int j)
{
    static int v = 1;

    if (i <= j)
    {
        int k = findMaxfreq(f, i, j);
        cost += f[k] * v;
        cout << k << "->" << f[k] << " * " << v << " = " << f[k] * v << endl;

        ++v;
        findMinCost(f, i, k - 1);
        findMinCost(f, k + 1, j);
        --v;
    }
}

int main()
{
    cout << "Number of inputs: ";
    cin >> N;

    int a[N];
    int b[N];

    for (int i = 0; i < N; i++)
    {
        cout << "\nEnter value-" << i + 1 << ": ";
        cin >> a[i];

        cout << "Enter frequency-" << i + 1 << ": ";
        cin >> b[i];
    }

    //bubble sort
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
        }
    }

    findMinCost(b, 0, N - 1);
    cout << "\n Total Cost of Greedy BST: " << cost;

    return 0;
}