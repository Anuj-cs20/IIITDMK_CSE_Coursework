#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    for (size_t i=0; i < 10; i++)
    {
        while (1)
        {
            try
            {
                cout << "Enter array element: ";
                cin >> a;
                if (!cin)
                {
                    throw true;
                }
                break;
            }
            catch (bool e)
            {
                cout << "Invalied input" << endl;
            }
        }
    }
}