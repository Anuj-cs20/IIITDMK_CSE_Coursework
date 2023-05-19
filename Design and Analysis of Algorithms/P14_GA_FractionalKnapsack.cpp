//Team : P14

// Greedy approach : Fractional Knapsack
// Max Profit

#include <bits/stdc++.h>
using namespace std;

void findMaxProfit(double *w, double *vw, double kn, int n)
{
    double a, p = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (kn == 0)
        {
            break;
        }
        else if (kn >= w[i])
        {
            kn -= w[i];
            p += (vw[i] * w[i]);
            cout << "\nObject with Weight: " << w[i] << " Profit: " << (vw[i] * w[i]) << endl;
        }
        else
        {
            a = (double)kn / w[i];
            p += (vw[i] * w[i] * a);
            cout << a << " ratio of ";
            cout << "\nObject with Weight: " << w[i] << " Profit: " << (vw[i] * w[i] * a) << endl;
            break;
        }
    }

    cout << "Total Profit: " << p;
}

void swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    double w;
    cout << "Enter Weight of Knapsack: ";
    cin >> w;

    int n;
    cout << "Number of inputs: ";
    cin >> n;

    double a[n], b[n], v;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter weight-" << i + 1 << ": ";
        cin >> a[i];
        cout << "Enter value-" << i + 1 << ": ";
        cin >> v;
        b[i] = (double)v / a[i];
    }

    //bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    findMaxProfit(a, b, w, n);

    return 0;
}