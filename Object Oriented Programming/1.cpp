#include <bits/stdc++.h>

using namespace std;

int main()
{
    int opc;
    bool aux =true;
    cin.exceptions(std::istream::failbit);
    do
    {
        try
        {
            cout << "PLEASE INSERT VALUE:" << endl;
            cin >> opc;
            aux = true;
        }
        catch (std::ios_base::failure &fail)
        {
            aux = false;
            cout << "PLEASE INSERT A VALID OPTION." << endl;
            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
    } while (aux == false);
    system("PAUSE");
}