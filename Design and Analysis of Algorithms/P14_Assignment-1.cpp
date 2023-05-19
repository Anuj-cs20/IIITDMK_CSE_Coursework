#include <iostream>
#include <vector>
using namespace std;

class A1
{
public:
	int sizeOfArray,max,smax,min,smin;
	vector<int> v;

	void userInput();
	void linearSearch();
	void twoHalvesSearch();
	void addSubtractMaxMin();
	void display();
};

int main() 
{	
	A1 array;
	array.userInput();

    array.linearSearch();
    cout << "Using simple Linear Search" << endl;
    array.display();

    array.twoHalvesSearch();
    cout << "Using Two Halves Search" << endl;
    array.display();

    array.addSubtractMaxMin();
    cout << "Using ++Min for smin --Max for smax Search" << endl;
    array.display();
    
    return 0;
}

void A1::userInput()
{
	cout << "Enter size of array of numbers" << endl;
	cin >> sizeOfArray;

	cout << "Enter array of numbers" << endl;
	for (int i = 0; i < sizeOfArray; ++i)
    {
        cin >> max;
        v.push_back(max);
    }
}

void A1::linearSearch()
{
	max = v[0];
	min = v[0];

	for (int i = 0; i < sizeOfArray; ++i)
	{
		if (max < v[i])
		{
			max = v[i];
		}
		if (min > v[i])
		{
			min = v[i];
		}
	}
    
    smin = max;
    smax = min;

	for (int i = 0; i < sizeOfArray; ++i)
	{
		if (smax < v[i] && v[i] < max)
		{
			smax = v[i];
		}
		if (smin > v[i] && v[i] > min)
		{
			smin = v[i];
		}
	}
}

void A1::twoHalvesSearch()
{
	int max1,smax1,min1,smin1,max2,smax2,min2,smin2;
   
    max1 = v[0];
	min1 = v[0];
	max2 = v[sizeOfArray/2];
	min2 = v[sizeOfArray/2];

    int n;
    if (sizeOfArray%2 == 0)
    {
    	n = sizeOfArray/2;
    }
    else
    {
    	n = sizeOfArray/2 + 1;
    }
    
	for (int i = 0; i < n; ++i)
	{
		if (max1 < v[i])
		{
			max1 = v[i];
		}
		if (min1 > v[i])
		{
			min1 = v[i];
		}

		if (max2 < v[i + sizeOfArray/2])
		{
			max2 = v[i + sizeOfArray/2];
		}
		if (min2 > v[i + sizeOfArray/2])
		{
			min2 = v[i + sizeOfArray/2];
		}
	}
    
    smin1 = max1;
    smax1 = min1;
    smin2 = max2;
    smax2 = min2;

	for (int i = 0; i < n; ++i)
	{
		if (smax1 < v[i] && v[i] < max1)
		{
			smax1 = v[i];
		}
		if (smin1 > v[i] && v[i] > min1)
		{
			smin1 = v[i];
		}

		if (smax2 < v[i + sizeOfArray/2] && v[i + sizeOfArray/2] < max2)
		{
			smax2 = v[i + sizeOfArray/2];
		}
		if (smin2 > v[i + sizeOfArray/2] && v[i + sizeOfArray/2] > min2)
		{
			smin2 = v[i + sizeOfArray/2];
		}
	}

	max = (max1 > max2) ? max1 : max2;
	min = (min1 < min2) ? min1 : min2;

	smax = (max == max1) ? max2 : max1;
	smin = (min == min1) ? min2 : min1;

	smax = (smax > smax1)? smax : smax1;
	smax = (smax > smax2)? smax : smax2;

	smin = (smin < smin1)? smin : smin1;
	smin = (smin < smin2)? smin : smin2;

	if (smin == min)
	{
		smin = (smin2 < smin1)? smin2 : smin1;
	}
	if (smax == max)
	{
		smax = (smax2 > smax1)? smax2 : smax1;
	}
}


void A1::addSubtractMaxMin()
{
	int i,j;

	max = v[0];
	min = v[0];

	for (i = 0; i < sizeOfArray; ++i)
	{
		if (max < v[i])
		{
			max = v[i];
		}
		if (min > v[i])
		{
			min = v[i];
		}
	}

	for (i = min + 1; i < max; ++i)
	{
		for (j = 0; j < sizeOfArray; ++j)
		{
			if (v[j] == i)
			{
				smax = v[j];
				break;
			}
		}
    }

    for (i = max - 1; i > min; --i)
	{
		for (j = 0; j < sizeOfArray; ++j)
		{
			if (v[j] == i)
			{
				smin = v[j];
				break;
			}
		}
    }
}

void A1::display()
{
   cout <<"First Maximum: "<<max<<endl;
   cout <<"First Minimum: "<<min<<endl;

   if (sizeOfArray > 2)
   {
   	    cout <<"Second Maximum: "<<smax<<endl;
        cout <<"Second Minimum: "<<smin<<endl;
   }
}