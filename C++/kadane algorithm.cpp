#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int maxsub(int a[], int size) 
{ 
   int max_so_far = 0, max_ending_here = 0; 
   for (int i = 0; i < size; i++) 
   { 
       max_ending_here = max_ending_here + a[i]; 
  
       if (max_so_far < max_ending_here) 
           max_so_far = max_ending_here; 
   } 
   return max_so_far; 
} 
int main() {
    fast;
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n]={0};
	    for(int i=0;i<n;i++) cin>>arr[i];
	    cout<<maxsub(arr,n)<<endl;
	}
	
	return 0;
}
