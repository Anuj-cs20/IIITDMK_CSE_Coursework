// Dynamic Programming to find Minimum number of Coins
// Unlimited number of coins of same kind are used
// We use the dynamic programming approach but with optimized space complexity

#include <bits/stdc++.h>
using namespace std;

int size, c = 0;

int findMinCoins(int *v, int *a, int k)
{
    int x, minCoins = INT_MAX;

    if (v[k] != INT_MIN)
    {
        return v[k];
    }

    if (k == 0)
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        if (a[i] <= k)
        {
            x = findMinCoins(v, a, k - a[i]);

            if (minCoins > x)
            {
                minCoins = x;
            }
        }
    }

    v[k] = minCoins;
    return v[k];
}

int main()
{

    int K;
    cout << "Enter Amount: ";
    cin >> K;

    cout << "Enter input array size: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        while (1)
        {
            cout << "Enter value of Coin-" << i + 1 << ": ";
            cin >> arr[i];
            if (arr[i] == 0)
            {
                cout << "Enter valied input" << endl;
            }
            else
            {
                break;
            }
        }
    }

    int mem[K + 1];
    for (int i = 0; i < K + 1; i++)
    {
        mem[i] = INT_MIN;
    }
    // mem[0] = 0;

    int tmp = findMinCoins(mem, arr, K);
    if (tmp == INT_MAX)
    {
        cout << "Change not possible" << endl;
    }
    else
    {
        cout << "Minimum number of coins required are: " << tmp << endl;
    }

    return 0;
}