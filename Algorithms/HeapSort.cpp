#include <iostream>
#include <vector>
using namespace std;


class PriorityQueue
{
	// return left child of A[i]
	int LEFT(int i) {
		return (2 * i + 1);
	}

	// return right child of A[i]
	int RIGHT(int i) {
		return (2 * i + 2);
	}

	
	void Heapify(vector<int> &A, int i, int size)
	{
		// get left and right child of node at index i
		int left = LEFT(i);
		int right = RIGHT(i);

		int largest = i;

		// compare A[i] with its left and right child to find largest value
		if (left < size && A[left] > A[i]) {
			largest = left;
		}

		if (right < size && A[right] > A[largest]) {
			largest = right;
		}

		// swap with child having greater value and call down on the child
		if (largest != i) {
			swap(A[i], A[largest]);
			Heapify(A, largest, size);
		}
	}

public:

	// Build-Heap
	PriorityQueue(vector<int> &A, int n)
	{
		// call heapify starting from last internal node all the way upto the root node
		int i = (n - 2) / 2;
		while (i >= 0) {
			Heapify(A, i--, n);
		}
	}

	// function to remove element with highest priority (present at root)
	int pop(vector<int> &A, int size)
	{
		
		if (size <= 0) {
			return -1;
		}

		int top = A[0];

		// replace the root of the heap with the last element of the array
		A[0] = A[size-1];

		// call heapify-down on root node
		Heapify(A, 0, size - 1);

		return top;
	}
};


void HeapSort(vector<int> &A, int n)
{
	
	PriorityQueue pq(A, n);

	
	while (n > 0) {
		A[n - 1] = pq.pop(A, n);
		n--;
	}
}

// Heap Sort algorithm implementation in C++
int main()
{
	vector<int> A = { 6, 4, 7, 1, 9, -2 };
	int n = A.size();

	
	HeapSort(A, n);

	
	for (int i = 0; i < n; ++i) {
		cout << A[i] << " ";
	}

	return 0;
}
