#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;

    int s = 0, x = 81;
    cout << "Ascii value of '('is " << int('(') << " + "
         << "Ascii value of ')'is " << int(')') << " = " << int('(') + int(')') << endl;

    for (size_t i = 0; i < str.size(); i++)
    {
        s += str[i];
    }

    if (s % x == 0)
    {
        cout << "Balanced Bracket Sequence " << endl;
    }
    else
    {
        cout << "Unbalanced Bracket Sequence " << endl;
    }

    return 0;
}