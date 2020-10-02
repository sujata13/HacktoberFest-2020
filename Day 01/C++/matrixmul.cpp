#include<iostream>
using namespace std;

int main()

{
  int a[10][10],b[10][10],c[10][10],i,j,k,m,n,p,q;
  
  cout<<"enter 1st matrix size";
  cin>>m>>n;
  cout<<"enter 2nd matrix size";
  cin>>p>>q;
  
  if(n==p)
  {
    cout<<"enter 1st mtarix elements";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    
    cout<<"enter 2nd mtarix elements";
    for(i=0;i<p;i++)
    for(j=0;j<q;j++)
    cin>>b[i][j];
    
    for(i=0;i<m;i++)
    for(j=0;j<q;j++)
    c[i][j]=0;
    
    for(i=0;i<m;i++)
    for(j=0;j<q;j++)
    for(k=0;k<p;k++)
    c[i][j] = c[i][j] + a[i][k] * b[k][j];
    
    cout<<"after multiplication matrix is \n";
   
      for(i=0;i<m;i++)
      {
    for(j=0;j<q;j++)
    
    cout<<"\t"<<c[i][j];
    cout<<"\n";
    }
  }
  else{
    cout<<"matrix multiplication is not possible";
  }
  
}
