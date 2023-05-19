//Team : P14

// Greedy Approach to find Minimum number of Coins
// Unlimited number of coins of same kind are used

#include <bits/stdc++.h>
using namespace std;

void findMinCoins(int *a, int n, int x)
{
    int c = 0;
    for (int i = x - 1; i >= 0; i--)
    {
        c += n / a[i];
        n -= (n / a[i]) * a[i];
    }

    if (n == 0)
    {
        cout << "Number of coins required: " << c;
    }
    else
    {
        cout << "\n!!!! CHANGE NOT POSSIBLE !!!!\n";
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