/*

    Name: K.Anuj
    Roll No.: cs20b1100

    Q4: List all feasible solutions of (0,1)-Knapsack.
        Feasible soln: A soln S containing objects is feasible if the sum of weights of objects in S does NOT exceed W.
        Optimal soln:  A feasible solution that maximizes the profit.

        Example:   3 objects with w_1=1, w_2=2, w_3=3, p_1=10,p_2=20,p_3=30, W=10.
        Any subset of {x_1,x_2,x_3} is a feasible solution.

    Write a C++ code that LISTs ALL feasible solutions.
    Also, print the count (the no of feasible solns)
    Marks: 15 marks

    Approach:
    Make pairs for the weight and the profits of the items and
    then try out all permutations of the array and including the weights
    until their is no such item whose weight is less than the remaining capacity of the knapsack.
    Meanwhile after including an item increment the profit for that solution by the profit of that item.

*/

#include <bits/stdc++.h>
using namespace std;

int c = 0;
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{
    // Mapping weights with Profits
    map<int, int> umap;

    set<vector<pair<int, int> > > set_sol;

    // Making Pairs and inserting into the map
    for (int i = 0; i < n; i++)
    {
        umap.insert({wt[i], val[i]});
    }

    int result = INT_MIN;
    int remaining_weight;
    int sum = 0;

    do
    {
        sum = 0;

        // Initially bag will be empty
        remaining_weight = W;
        vector<pair<int, int> > possible;

        for (int i = 0; i < n; i++)
        {
            if (wt[i] <= remaining_weight)
            {
                remaining_weight -= wt[i];
                auto itr = umap.find(wt[i]);
                sum += (itr->second);

                possible.push_back({itr->first, itr->second});
            }
        }

        // sort function is in algorithm header file
        sort(possible.begin(), possible.end());
        if (sum > result)
        {
            result = sum;
        }

        if (set_sol.find(possible) == set_sol.end())
        {
            for (auto sol : possible)
            {
                cout << sol.first << ": " << sol.second << ", ";
            }
            cout << endl;
            ++c;
            set_sol.insert(possible);
        }

        // next_permutation function is in algorithm header file
        // To iterate over all the possible permutations of array
    } while (next_permutation(wt.begin(), wt.end()));

    return result;
}

int main()
{
    int W;
    cout << "Enter Total Weight OF Knapsack:";
    cin >> W;

    int n;
    cout << "Enter The Number OF Weights :";
    cin >> n;

    vector<int> val, wt;
    int dum;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter weight-" << i + 1 << ": ";
        cin >> dum;
        wt.push_back(dum);

        cout << "Enter Profits-" << i + 1 << ": ";
        cin >> dum;
        val.push_back(dum);
    }
    cout << endl;

    int max = knapSack(W, wt, val, n);
    cout << "\nMaximum Profit = " << max;
    cout << "\nThe Number of feasible solns are: " << c;
    return 0;
}