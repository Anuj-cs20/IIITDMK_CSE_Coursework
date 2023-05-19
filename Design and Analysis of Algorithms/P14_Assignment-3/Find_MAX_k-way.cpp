/*  
    TEAM: P14
    Divide and Conquer Paradigm
    1. Find MAX using 1-way, 2-way, 3-way, k-way approach
*/    

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class findMax
{
public:
    void kwaySearch(int k);
};

void findMax::kwaySearch(int k)
{
    int max[k];
    int size,Max = INT_MIN;
    vector <int> v;

    cout << "Enter size of array of numbers: ";
    cin >> size;

    int tmp;
    cout << "Enter array of numbers: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    if (size%k != 0)
    {
        for (int i = 0; i < k - size%k; ++i)
        {
            v.push_back(INT_MIN);
        }
    }

    cout<<"\nArray elements after adding dummy numbers:"<<endl;
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";

    for (int i = 0; i < k; ++i)
    {
        cout<<"Part-"<<i+1<<"\t";
    }
    cout<<endl;

    for (int i = 0; i < k; ++i)
    { 
        max[i] = INT_MIN;
        for (int j = 0; j < v.size()/k; ++j)
        {
            if ( max[i] < v[j+i*(v.size()/k)] )
            {
                max[i] = v[j+i*(v.size()/k)];
            }
            cout<<v[j+i*(v.size()/k)]<<" ";
        }
        cout<<"\t";
    }
    cout<<"\n\n";

    for (int i = 0; i < k; ++i)
    {
        cout<<"MAX-"<<i+1<<"\t";
    }
    cout<<endl;
    
    for (int i = 0; i < k; ++i)
    {
        if (Max < max[i])
        {
            Max = max[i];
        }
        cout<<max[i]<<"\t";
    }
    cout<<"\n\n";
    cout<<"Maximum of array is: "<<Max;
    cout<<"\n\n";
}

int main()
{
    findMax obj;
    int choice;
    while(1)
    {
        cout<<"Enter value of 'k' in k-way tree or '0' to EXIT: ";
        cin>>choice;

        if (choice == 0)
        {
            break;
        }
        else
        {
            obj.kwaySearch(choice);
        }
    }
    
    return 0;
}