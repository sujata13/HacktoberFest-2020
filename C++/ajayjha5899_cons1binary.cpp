// by @chaupatt (ajayjha5899 on github)
/*
Given n, find all numbers of n bits having atleast
2 consecutive 1's in their binary representation.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<int> ss;

void noConsOnes(int n, vector<int> sol){
    int s = sol.size();
    if(s<=n){
        int curr = 0;
        for(int i=0; i<s; i++){
            curr += sol[i]*pow(2,s-i-1);
        }
        ss.insert(curr);

        int lsb = sol[s-1];
        if(lsb==1){
            sol.push_back(0);
            noConsOnes(n, sol);
        } 
        else{
            sol.push_back(0);
            noConsOnes(n, sol);
            sol.pop_back();
            sol.push_back(1);
            noConsOnes(n, sol);
        }
    }
}

int main(){
    int n; cin >> n;
    vector<int> sol;
    sol.push_back(1);
    noConsOnes(n, sol);

    int ans = pow(2,n);
    ans = (ans-1)-ss.size();
    cout << ans << endl;
    return 0;
}