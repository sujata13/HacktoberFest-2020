#include <bits/stdc++.h>
using namespace std;

int getEuclidGCD(int a, int b){
    if(b==0)
        return a;
    else
        return getEuclidGCD(b,a%b);
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<": "<<getEuclidGCD(a,b);
    return 0;
}
