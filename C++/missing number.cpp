#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,sum1,sum2;
	cin>>t;
	while(t--)
	{   sum1=0;
	    sum2=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) 
	    {
	        cin>>a[i];
	        sum2+=a[i];
	    }
	    sum1=(n*(n+1))/2;
	    //d=sum1-sum2;
	    cout<<sum1-sum2<<endl; 
	}
	
	
	
	
	return 0;
}
