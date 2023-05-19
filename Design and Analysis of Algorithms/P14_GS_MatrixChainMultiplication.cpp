//Team : P14

// Greedy Strategy for Matrix Chain Multiplication

#include <bits/stdc++.h>
using namespace std;

void findMinProduct(int *a, int k)
{
    static int m;
    int index, prod = INT_MAX, j = 0;
    int arr[k - 1];

    if (k == 2)
    {
        cout << "Total number of Multiplications: " << m;
    }
    else
    {
        for (int i = 1; i < k - 1; i++)
        {
            if (prod > a[i - 1] * a[i + 1])
            {
                prod = a[i - 1] * a[i + 1];
                index = i;
            }
        }

        m += a[index - 1] * a[index + 1] * a[index];

        for (int i = 0; i < k; i++)
        {
            if (i != index)
            {
                arr[j] = a[i];
                ++j;
            }
        }
        findMinProduct(arr, k - 1);
    }
}

int main()
{
    int s;
    cout << "Enter size of input: ";
    cin >> s;

    int arr[s];
    cout << "Enter array elements: ";
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    findMinProduct(arr, s);

    return 0;
}