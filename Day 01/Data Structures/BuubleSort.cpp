#include<iostream.h>
#include<stdio.h>

using namespace std;

void display(int *a, int n) 
{
   for(int i = 0; i<n; i++)
      cout << a[i] << " ";
   cout << endl;
}

void buuble_sort(int *a, int n)
{
int i,j,temp=0;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[ij] > a[j+1])
{
temp = a[j];
a[j] = a[j+1];
a[j+1] = temp;
}
}
}
}

int main()
{
int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int a[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) 
   {
      cin >> a[i];
   }
   cout << "Array before Sorting: ";
   display(a, n);
   bubble_sort(a, n);
   cout << "Array after Sorting: ";
   display(a, n);
   return 0;
}