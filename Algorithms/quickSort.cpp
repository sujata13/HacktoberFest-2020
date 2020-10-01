/* Implementation of QuickSort in C++ */
#include<iostream> 
using namespace std;

// swap to two numbers 
void swap(int* a, int* b) { 

	int t = *a; 
	*a = *b; 
	*b = t; 
} 

// partition of the array w.r.t to pivot element
int partition (int arr[], int low, int high) 
{ 

	int pivot = arr[high], i = (low - 1);; 
	for (int j = low; j <= high- 1; j++) 
	{ 		
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

// display of output
void display(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++){
		cout << arr[i] << " ";
	} 
	cout << "\n";
} 

// Driver code
int main() { 

	int n;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter element of array: ";
	for(int i = 0; i < n; i++)
	cin >> arr[i]; 
	quickSort(arr, 0, n-1); 
	cout << "Sorted array: ";; 
	display(arr, n); 
	return 0; 
} 

// Avg time Complexity:	O(n log n)

