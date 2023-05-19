//Team : P14

// Greedy Approach to find Minimum number of Coins
// Only one coin is available of same kind

#include <bits/stdc++.h>
using namespace std;

void findMinCoins(int *a, int n, int x)
{
    int c = 0;
    cout << "Coins used: ";
    for (int i = x - 1; i >= 0; i--)
    {
        if (n >= a[i])
        {
            n -= a[i];
            cout << a[i] << " ";
        }
    }

    if (n != 0)
    {
        cout << "\n!!!! CHANGE NOT POSSIBLE !!!!";
    }
}

int main()
{
    int N;
    cout << "Enter Amount: ";
    cin >> N;

    int x;
    cout << "Number of different coins available: ";
    cin >> x;

    int arr[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Enter value of Coin-" << i + 1 << ": ";
        cin >> arr[i];
    }

    sort(arr, arr + x);
    findMinCoins(arr, N, x);

    return 0;
}