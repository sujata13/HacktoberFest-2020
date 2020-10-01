#include <iostream>
using namespace std;

void tukar(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void sorting(int arr[], int arrsize)
{
    for(int i=arrsize-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                tukar(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<arrsize;i++){
        cin>>arr[i];
    }
    sorting(arr,arrsize);
    for(int i=0;i<arrsize;i++){
        cout<<arr[i];
    }
}
