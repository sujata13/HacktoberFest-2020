/* Implementation of MergeSort using C++ */
// Time Complexity: O(n log n)

#include<iostream>
using namespace std;

/* swap two numbers */
void swapping(int &a, int &b) {    
 
   int temp;
   temp = a;
   a = b;
   b = temp;
}

/* Display Array */
void display(int *array, int size) {

   for(int i = 0; i < size; i++)
      cout << array[i] << " ";
      cout << endl;
}

/* merging of array */
void merge(int *array, int l, int m, int r) {
  
   int i, j, k, nl, nr; 
   nl = m - l + 1; nr = r - m;
   int larr[nl], rarr[nr];
  
   for(i = 0; i < nl; i++)
      larr[i] = array[l+i];
  
   for(j = 0; j < nr; j++)
      rarr[j] = array[m+1+j];
  
   i = 0; j = 0; k = l;
   
   while(i < nl && j < nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i < nl) {      
      array[k] = larr[i];
      i++; k++;
   }
   while(j < nr) {   
      array[k] = rarr[j];
      j++; k++;
   }
}

// Recursion function
void mergeSort(int *array, int l, int r) {
   
   int m;
   if(l < r) {
      int m = l + ( r - l ) / 2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

/* Driver Code */
int main() {

   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];    
   cout << "Enter your elements: ";
   for(int i = 0; i < n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   mergeSort(arr, 0, n-1);    
   cout << "After Sorting: ";
   display(arr, n);
   return 0;
}

// output
/*
Enter the number of elements: 10
Enter your elements: 1 6 4 7 54 8866 3 121 3 11
Array before Sorting: 1 6 4 7 54 8866 3 121 3 11 
After Sorting: 1 3 3 4 6 7 11 54 121 8866 
*/

