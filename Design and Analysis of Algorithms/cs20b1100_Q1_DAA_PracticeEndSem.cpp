/*

    Name: K.Anuj
    Roll No.: cs20b1100

    
    Q1: Knapsack with all weights same (w_i is same for all objects)
        Present a GREEDY algorithm and its implementation in C++. 
        Run-time of your algorithm must be o(n^2)  (little-oh of n^2).

    Marks: 3 (logic), 5 (code), 2 (run-time analysis, output) = 10 marks

    Approach:
    Sort profits and as greedy approach says take the object with max profit
    So, take the last object (after sorting profits) check weight 
    if it is less, take that object and update knapsack weight and profit also
    repeat the process untill knapsack weight is less than weight
    Then print total profit

    Complexity:
    bubble sort complexity + for loops = O(n^2) + 2n + constant

    Total Complexity = O( n^2 ). 
*/

#include <bits/stdc++.h>
using namespace std;

void findMaxProfit(double w, double *v, double kn, int n)
{
    double p = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (kn >= w)
        {
            kn -= w;
            p += (v[i]);
            cout << "Object with Weight: " << w << " Profit: " << (v[i]) << endl;
        }
        else
        {
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
    cout << "Enter Number of Objects: ";
    cin >> n;

    double a, b[n], v;
    cout << "\nEnter weight per Object: ";
    cin >> a;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Profit of Object-" << i + 1 << ": ";
        cin >> b[i];
    }

    //bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                swap(&b[j], &b[j + 1]);
            }
        }
    }
    cout << "\n";

    findMaxProfit(a, b, w, n);

    return 0;
}