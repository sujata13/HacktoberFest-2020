#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter a Number: ";
    cin>>n;
    int digits=1+log10(n);
    cout<<n<<" is a "<<digits<<" digit number"<<endl;
}