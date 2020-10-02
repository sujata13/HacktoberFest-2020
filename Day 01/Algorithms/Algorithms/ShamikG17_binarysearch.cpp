#include <iostream>
using namespace std;

int binarySearch(int arr[], int b, int e, int x){
    
    int mid;
    if(e >= b){
        mid = b+(e-1)/2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] > x){
            return binarySearch(arr, b, mid-1, x);
        }
        
        return binarySearch(arr, mid+1, e, x);
    }

    return -1;

}

int main(){
    int n;
    int x;

    cout << "Enter number of element in array: "; 
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: \n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Enter the number which you want to find the index for: ";
    cin >> x;

    int result = binarySearch(arr, 0, n-1, x);
    
    if(result == -1){
        cout << "Element is not in the array.";
    }
    else{
        cout << "Index of element: " << result;
    }

    return 0;
}