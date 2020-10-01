#include<bits/stdc++.h>
using namespace std;
int main()
{
	string t,t1;
	//cin>>t;
	getline(cin,t);
	stack<char> s;
	for(int i=0;i<t.length();i++)
	{
		s.push(t[i]);
	}
	while (!s.empty()) 
    { 
        cout<< s.top(); 
        s.pop(); 
    } 
    //cout << '\n';
	//cout<<t1<<endl;
}
