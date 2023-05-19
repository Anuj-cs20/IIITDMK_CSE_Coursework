#include <iostream>
using namespace std;
template <class T>
class sortt
{
public:
    T a[50];
    int n;
    void accept()
    {
        cout << "Enter no. of elements:\n";
        cin >> n;
        cout << "enter a elements\n";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    void selection_sort()
    {
        T temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << "\n";
        }
    }
};

int main()
{
    int v;
    char ch;
    sortt<int> s1;
    sortt<float> s2;

    cout << "*****SELECTION SORT*******\n";
    do
    {
        cout << "sorting of integer and float array"
             << "\n";
        cout << "1.for int array\n";
        cout << "2.for float array\n";
        cout << "enter your choice\n";
        cin >> v;
        switch (v)
        {
        case 1:
            s1.accept();
            cout << "\nElements are:\n";
            s1.display();
            s1.selection_sort();
            cout << "\nSorted elements are:\n";
            s1.display();
            break;
        case 2:
            s2.accept();
            cout << "\nElements are:\n";
            s2.display();
            s2.selection_sort();
            cout << "\nSorted elements are:\n";
            s2.display();
            break;
        }
        cout << "\n do you want to continue";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}