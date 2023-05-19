#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int get_parity(vector<int> hamming, int check_gp)
{
    int i = check_gp, output = 0;
    hamming[i] = 0;
    while (i <= hamming.size())
    {
        int x = check_gp;
        while (x-- && i <= hamming.size())
        {
            output = output ^ hamming[i]; // doing xor for count purpose
            i++;
        }
        i = i + check_gp;
    }

    return output;
}

bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
    string s;
    cout << "enter string :";
    cin >> s;
    int r = 0, i = 0;

    while (pow(2, r) < (s.size() + r + 1))
    {
        r++;
    }
    cout << "r : " << r << "\n";
    int n = s.size() + r;
    vector<int> hamming(n + 1);

    while (pow(2, i) <= n)
    {
        hamming[pow(2, i)] = -1;
        i++;
    }

    int j = s.size() - 1;
    for (i = 1; i <= n; i++)
    {
        if (hamming[i] != -1 && j >= 0)
        {
            hamming[i] = s[j--] - 48;
        }
    }

    for (int x = 1; x <= n; x++)
    {
        if (hamming[x] == -1)
        {

            hamming[x] = get_parity(hamming, x);
            cout << "parity " << x << " : " << hamming[x] << "\n";
        }
    }

    cout << "recievers data : \n";
    string recievers_data;
    cin >> recievers_data;
    vector<int> p(n + 1), a;
    i = n;
    for (auto c : recievers_data)
    {
        p[i--] = c - '0';
    }

    for (int x = 1; x <= n; x++)
    {
        if (isPowerOfTwo(x))
        {

            int check = get_parity(p, x);
            if (check != p[x])
            {
                cout << "error in parity " << x << "\n";
                a.push_back(1);
            }
            else
            {
                a.push_back(0);
            }
        }
    }
    int output = 0;

    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == 1)
        {
            output += pow(2, i);
        }
    }
    if (output != 0)
        cout << "we need to invert " << output << " th bit\n";
    else
    {
        cout << "entered data is correct\n";
    }
    return 0;
}