/*

    Name: K.Anuj
    Roll No.: cs20b1100

    Q3: (0, 1/2, 1)-Knapsack
    In this version, each x_i takes the value 0 or 1/2 or 1.
    That is, we include the object in full (1) or in half (1/2) or not included at all (0).
    Present a DP (clearly mention the recursive solution,
    optimal substructure in the code itself) and its implementation in C++. 
    Run-time must be polynomial in 'n'.

    Marks: 5 (logic- for writing recursive soln, opt structure), 
    8 (code), 2 (run-time analysis, output) = 15 marks

    Approach:
    Consider all subsets of items and calculate the total weight and value of all subsets.
    Consider the only subsets whose total weight is smaller than W.
    From all such subsets, pick the maximum value subset
    Create a 2-D array to store a particular state (n, w) profit if we get it the first time. 
    Now if we come across the same state (n, w) again instead of calculating it in exponential complexity
    we can directly return its result stored in the table in constant time.

    Complexity:
    
    complexity = O( N*W ) + c. 
    where ‘N’ is the number of weight element and ‘W’ is capacity.
    As for every weight element we traverse through all weight capacities 1<=w<=W.
    'c' for half weighted objects

    Total Time Complexity = O( N*W ). 

*/

#include <bits/stdc++.h>
using namespace std;

double knapSackRec(int W, double *wt, double *val, int i, double **dp)
{
    // Store value in a table before return
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }

    // finding max btw half anf full values of objects.
    if (wt[i] > W)
    {
        // check for 1/2 weight
        if (wt[i] / 2 > W)
        {
            dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        }
        else
        {
            // find max of (0,0.5) varients and store
            dp[i][W] = max(val[i] / 2 + knapSackRec(W - wt[i] / 2, wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp));
        }

        return dp[i][W];
    }
    else
    {
        // find max of (0,0.5,1) varients and store
        dp[i][W] = max(val[i] / 2 + knapSackRec(W - wt[i] / 2, wt, val, i - 1, dp),
                       max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, dp), knapSackRec(W, wt, val, i - 1, dp)));

        return dp[i][W];
    }
}

int main()
{
    int W;
    cout << "Enter Total Weight OF Knapsack:";
    cin >> W;

    int n;
    cout << "Enter The Number OF Weights :";
    cin >> n;

    double wt[n], val[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter weight-" << i + 1 << ": ";
        cin >> wt[i];
        cout << "Enter Profits-" << i + 1 << ": ";
        cin >> val[i];
    }
    cout << endl;

    // double pointer to declare the
    // table dynamically
    double **dp;
    dp = new double *[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = new double[W + 1];
    }

    // loop to initially fill the table with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "Total Profit: " << knapSackRec(W, wt, val, n - 1, dp);
    return 0;
}