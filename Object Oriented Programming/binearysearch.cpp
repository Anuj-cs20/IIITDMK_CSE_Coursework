#include <iostream>
#include <vector>
#include <climits>
#pragma GCC optimize("Ofast")
using namespace std;

#define NL "\n"
#define int long long int
#define all(x) x.begin() x.end()
const int mod = 1e9 + 7;

void readInputFile()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> v;
int size, k;

void bin()
{
    int l = 0, r = size - 1, m;

    while (l + 1 < r)
    {
        m = l + r / 2;
        if (v[m] < k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }

    cout << l << r;
}

void solve()
{
    cin >> size;
    cin >> k;
    v[0] = INT_MIN;

    for (size_t i = 0; i < size + 1; i++)
    {
        cin >> v[i];
    }
    v[size + 1] = INT_MAX;
    bin();
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    readInputFile();
    solve();

    return 0;
}
