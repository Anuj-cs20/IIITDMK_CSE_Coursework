/*

    Name: K.Anuj
    Roll No.: cs20b1100

    Q2: Knapsack with all profits same (p_i is same for all objects)
        Present a GREEDY algorithm and its implementation in C++.  
        Run-time of your algorithm must be o(n^2)  (little-oh of n^2).

    Marks: 3 (logic), 5 (code), 2 (run-time analysis, output) = 10 marks

    Approach:
    Sort weights and as greedy approach says take max objects(as profits are equal) for max profit
    So, take the first object (after sorting weights) check weight 
    if it is less, take that object and update knapsack weight and profit also
    repeat the process untill knapsack weight is less than weight
    Then print total profit

    Complexity:
    bubble sort complexity + for loops = O(n^2) + 2n + constant
    
    Total Complexity = O( n^2 ). 
*/

#include <bits/stdc++.h>
using namespace std;

void findMaxProfit(double *w, double v, double kn, int n)
{
    double p = 0;
    for (int i = 0; i < n; i++)
    {
        if (kn >= w[i])
        {
            kn -= w[i];
            p += (v);
            cout << "Object with Weight: " << w[i] << " Profit: " << (v) << endl;
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

    double a[n], b;
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of Object-" << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "\nEnter Profit per Object: ";
    cin >> b;

    //bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    cout << "\n";

    findMaxProfit(a, b, w, n);

    return 0;
}