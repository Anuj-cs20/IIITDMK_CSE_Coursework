#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    vector<int> v = {2, 3, 4, 5};
    vector<int>::iterator it;
    for (auto it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}