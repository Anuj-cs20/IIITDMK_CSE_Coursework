// Dynamic Programming for  Optimal Binary Search tree

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int sumFreq(int *f, int x, int y)
{
    int sum = 0;
    for (int i = x; i <= y; i++)
    {
        sum += f[i];
    }

    return sum;
}

void findMaxfreq(int *freq, int n)
{
    int t[n][n];

    for (int i = 0; i < n; i++)
    {
        t[i][i] = freq[i];
    }

    for (int l = 2; l <= n; l++) // {1,2,3,4} A1,A2,A3
    {
        for (int i = 0; i <= n - l + 1; i++) // l = 2,i=0,j=2
        {
            int j = i + l - 1;
            t[i][j] = INT_MAX;

            for (int k = i; k <= j; k++)//0<=k<=2
            {
                int c = ((k > i) ? t[i][k - 1] : 0) + ((k < j) ? t[k + 1][j] : 0) + sumFreq(freq, i, j);
                //k = 0,c = 0+(1,2)+f[1..2]
                //k = 1,c = (0,0) + (2,2)+f[2]
                //k = 2,c = (0,1) + 0 + f[0...1]          

                if (c < t[i][j])
                {
                    t[i][j] = c;
                }
            }
        }
    }

    cout << "\nPrinting Table....." << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            t[j][i] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        t[i][i] = freq[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Total Cost of DP optBST: " << t[0][n - 1];
}

int main()
{
    int N;
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

    findMaxfreq(b, N);
    return 0;
}