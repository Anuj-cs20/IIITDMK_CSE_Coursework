/*
   TEAM:P14
   Divide and Conquer Paradigm
   3. Implement an Iterative and a Recursive algorithm for binary search, ternary search.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class binarySearch
{
private:
   int size,X;
   vector <int> vb;

public:
   void userInput(int n);
   void iterative(int start,int end);
   void recursive(int start,int end);
};

class ternarySearch
{
private:
   int size,X;
   vector <int> vt;

public:
   void userInput(int n);
   void iterative(int start,int end);
   void recursive(int start,int end);
};

void binarySearch::userInput(int n)
{
   int tmp;

   this->size = n;
   cout<<"Enter elements of the array: ";
   for (int i = 0; i < size; ++i)
   {
      cin>>tmp;
      vb.push_back(tmp);
   }

   stable_sort(vb.begin(),vb.end());

   cout<<"Enter value you want to search: ";
   cin>>X;
}

void ternarySearch::userInput(int n)
{
   int tmp;
   this->size = n;

   cout<<"Enter elements of the array: ";
   for (int i = 0; i < size; ++i)
   {
      cin>>tmp;
      vt.push_back(tmp);
   }

   stable_sort(vt.begin(),vt.end());

   cout<<"Enter value you want to search: ";
   cin>>X; 
}

void binarySearch::recursive(int start,int end)
{
   if (start <= end)
   {
      int mid = start + (end - start)/2;
      
      if (X > vb[mid])
      {
         recursive(mid + 1,end);
      }
      else if (X < vb[mid])
      {
         recursive(start,mid - 1);
      }
      else
      {
         cout<<"YES,Index in sorted array: "<<mid<<endl;
      }
   }
   else
   {
      cout<<"no";
   }
}

void ternarySearch::recursive(int start,int end)
{
   if (start <= end)
   {
      int mid1 = start + (end - start)/3;
      int mid2 = end - (end - start)/3;
      
      if (X > vt[mid1] && X < vt[mid2])
      {
         recursive(mid1 + 1,mid2 - 1);
      }
      else if (X < vt[mid1])
      {
         recursive(start,mid1 - 1);
      }
      else if (X > vt[mid2])
      {
         recursive(mid2 + 1,end);
      }
      else if (X == vt[mid2])
      {
         cout<<"YES,Index in sorted array:"<<mid2<<endl;
      }
      else 
      {
         cout<<"YES,Index in sorted array:"<<mid1<<endl;
      }
   }
   else
   {
      cout<<"no";
   }
}

void binarySearch::iterative(int start,int end)
{
   int mid = start + (end - start)/2;
   while(start <= end)
   {
      if (X > vb[mid])
      {
         start = mid + 1;
      }
      else if (X < vb[mid])
      {
         end = mid - 1;
      }
      else
      {
         cout<<"YES,Index in sorted array: "<<mid<<endl;
         break;
      }
      mid = start + (end - start)/2;
   }

   if (start>end)
   {
      cout<<"no"<<endl;
   }
}

void ternarySearch::iterative(int start,int end)
{
   int mid1 = start + (end - start)/3;
   int mid2 = end - (end - start)/3;
   while(start <= end)
   {
      if (X > vt[mid1] && X < vt[mid2])
      {
         start = mid1 + 1;end = mid2 - 1;
      }
      else if (X < vt[mid1])
      {
         end = mid1 - 1;
      }
      else if (X > vt[mid2])
      {
         start = mid2 + 1;
      }
      else if (X == vt[mid2])
      {
         cout<<"YES,Index in sorted array:"<<mid2<<endl;
         break;
      }
      else 
      {
         cout<<"YES,Index in sorted array:"<<mid1<<endl;
         break;
      }
      mid1 = start + (end - start)/3;
      mid2 = end - (end - start)/3;
   }

   if (start>end)
   {
      cout<<"no"<<endl;
   }
}

int main()
{
   binarySearch obj1;
   int size;
   cout<<"Enter size of the array: ";
   cin>>size;
   obj1.userInput(size);
   cout<<"Binary Search:-"<<endl;
   cout<<"Recursive Method: ";
   obj1.recursive(0,size - 1);
   cout<<"Iterative Method: ";
   obj1.iterative(0,size - 1);
   cout<<endl;

   ternarySearch obj2;
   cout<<"Enter size of the array: ";
   cin>>size;
   obj2.userInput(size);
   cout<<"Ternary Search:-"<<endl;
   cout<<"Recursive Method: ";
   obj2.recursive(0,size - 1);
   cout<<"Iterative Method: ";
   obj2.iterative(0,size - 1);
    
   return 0;
}