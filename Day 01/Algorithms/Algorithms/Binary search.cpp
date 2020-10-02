#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int binarysearch(int element,int arr[],int size)
{
	int left=0,right=size-1,mid;
	while(left <= right)
	{
		mid=floor((left + right)/2);
		if(element == arr[mid])
		return mid;
		else if(element < arr[mid])
		right = mid-1;
		else
		left = mid+1;
	}
	return -1;
}
int main()
{
	int size;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	
	int arr[size];
	cout<<"Enter Sorted Array"<<endl;
	for(int i=0;i<size;i++)
	cin>>arr[i];
	
	int element;
	cout<<"Enter search element"<<endl;
	cin>>element;
	int ans = binarysearch(element,arr,size);
	if(ans!=-1)
	cout<<"Element found at "<<ans<<" index"<<endl;
	else
	cout<<"Element is not present in array"<<endl;
}
