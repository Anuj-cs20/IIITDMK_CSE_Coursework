/*
   TEAM: P14
   Divide and Conquer Paradigm
   2. Count the number of negative numbers in an integer array using 2-way and 3-way approach.
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class countNegative
{
private:
   vector <int> v1,v2;

public:
   countNegative(){};
   void userInput();
   void using2wayApproach();
   void using3wayApproach();
   ~countNegative(){};
};

void countNegative::userInput()
{
   int size,tmp;
   cout<<"Enter size of array: ";
   cin>>size;

   cout << "Enter array of numbers: ";
   for (int i = 0; i < size; ++i)
   {
      cin>>tmp;
      v1.push_back(tmp);
      v2.push_back(tmp);
   }
}

void countNegative::using2wayApproach()
{
   int c1 = 0,c2 = 0;
   int t = v1.size();
   if (t%2 != 0)
   {
      for (int i = 0; i < 2 - t%2; ++i)
      {
         v1.push_back(INT_MAX);
      }
   }

   cout<<"Part-1"<<endl;

   for (int i = 0; i < v1.size()/2; ++i)
   {
      if (v1[i] < 0)
      {
         ++c1;
      }
      cout<<v1[i]<<" ";
   }
   cout<<"\n\n";
   cout<<"Part-2"<<endl;

   for (int i = v1.size()/2 + 1; i < v1.size(); ++i)
   {
      if (v1[i] < 0)
      {
         ++c2;
      }
      cout<<v1[i]<<" ";
   }
   cout<<"\n\n";

   cout<<"count-1 + count-2 = TotalCount"<<endl;
   cout<<c1<<" + "<<c2<<" = "<<c1+c2;
   cout<<"\n\n";
}

void countNegative::using3wayApproach()
{
   int c1 = 0,c2 = 0,c3 = 0;
   int s = v2.size();
   if (s%3 != 0)
   {
      for (int i = 0; i < 3 - s%3; ++i)
      {
         v2.push_back(INT_MAX);
      }
   }

   cout<<"Part-1"<<endl;

   for (int i = 0; i < v2.size()/3; ++i)
   {
      if (v2[i] < 0)
      {
         ++c1;
      }
      cout<<v2[i]<<" ";
   }
   cout<<"\n\n";
   cout<<"Part-2"<<endl;

   for (int i = v2.size()/3; i < 2*v2.size()/3; ++i)
   {
 
      if (v2[i] < 0)
      {
         ++c2;
      }
      cout<<v2[i]<<" ";
   }
   cout<<"\n\n";
   cout<<"Part-3"<<endl;

   for (int i = 2*v2.size()/3; i < v2.size(); ++i)
   {
      if (v2[i] < 0)
      {
         ++c3;
      }
      cout<<v2[i]<<" ";
   }
   cout<<"\n\n";

   cout<<"count-1 + count-2 + count-3 = TotalCount"<<endl;
   cout<<c1<<" + "<<c2<<" + "<<c3<<" = "<<c1+c2+c3;
   cout<<"\n";
}

int main()
{
   countNegative obj;
   obj.userInput();
   cout<<"Using 2-way Approach:"<<endl;
   obj.using2wayApproach();
   cout<<"Using 3-way Approach:"<<endl;
   obj.using3wayApproach();

   return 0;
}