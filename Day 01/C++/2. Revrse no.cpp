#include <iostream>
#include<math.h>
using namespace std;

int main(){
  int n,m;
  int ans=0;

  cin>>n;
  while(n!=0){
    m = n%10;
    ans = ans*10 + m;
    n=n/10;

  }
cout<<ans;
}
