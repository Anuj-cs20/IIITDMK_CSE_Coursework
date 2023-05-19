/*

Roll Number: cs20b1100
Name: K.Anuj

Q2 - Implement Quicksort with 2 pivots.   
    Choose two arbitrary elements of the given array A, say x and y.  
    Maintain three windows at each iteration, 
    assuming x < y, the first window has elements < x, 
    the second window has elements between x and y, and 
    the third window has elements > y.

Marking Scheme: 
Input acceptance and pivot selection (2 marks), 
window creation and swapping (8 marks) 
recursive call arguments (3 marks) 
output (2 marks) 
- total 15 marks.

Process: 

1. Choose outermost elements as pivots.
2. Perform Quick sort in that 3 window
3. Print sorted array.
4. Exit.

Asymptotic analysis: same as Quick Sort O(nlog(n)).

*/

#include <iostream>
using namespace std;

void swap(int *A, int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void quickSort(int *A, int left, int right)
{
    if (right > left)
    {

        if (A[left] > A[right])
            swap(A, left, right);
        int p = A[left], q = A[right];

        int x = left + 1, y = right - 1, k = x;
        while (k <= y)
        {
            if (A[k] < p)
            {
                swap(A, k, x);
                ++x;
            }
            else if (A[k] >= q)
            {
                while (A[y] > q && k < y)
                    --y;
                swap(A, k, y);
                --y;
                if (A[k] < p)
                {
                    swap(A, k, x);
                    ++x;
                }
            }
            ++k;
        }
        --x;
        ++y;

        // Swap pivots to final place
        swap(A, left, x);
        swap(A, right, y);

        // Recursively sort partitions
        quickSort(A, left, x - 1);
        quickSort(A, x + 1, y - 1);
        quickSort(A, y + 1, right);
    }
}

int main()
{
    int n, l, r;
    cout << "Enter size of input n: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Enter sorted elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}