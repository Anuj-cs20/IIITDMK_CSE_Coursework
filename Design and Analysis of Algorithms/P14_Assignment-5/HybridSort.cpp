/*
    TEAM: P14
    1. Hybrid Sorting: Insertion sort + Merge sort - Consider a large sized array (size at least 1000).
    Perform Merge sort recursively until the problem size becomes less than or equal to 20.
    When problem size becomes less than or equal to 20, perform Insertion sort.
*/

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long int

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int *A, int *l, int leftcount, int *r, int rightcount)
{
    int i = 0, j = 0, k = 0;

    while (i < leftcount && j < rightcount)
    {
        if (l[i] < r[j])
        {
            A[k++] = l[i++];
        }
        else
        {
            A[k++] = r[j++];
        }
    }

    while (i < leftcount)
    {
        A[k++] = l[i++];
    }

    while (j < rightcount)
    {
        A[k++] = r[j++];
    }
}

void mergeSort(int *A, int n)
{
    int mid = n / 2;
    if (n <= 20)
    {
        insertionSort(A, n);
    }
    else
    {
        int *L = new int[mid];
        int *R = new int[n - mid];

        for (int i = 0; i < mid; i++)
        {
            L[i] = A[i];
        }
        for (int i = mid; i < n; i++)
        {
            R[i - mid] = A[i];
        }

        mergeSort(L, mid);
        mergeSort(R, n - mid);
        merge(A, L, mid, R, n - mid);
        delete[] L;
        delete[] R;
    }
}

int32_t main()
{
    int size;
    cout << "Enter size of input Array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements of your Array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}