#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;

	//Upper

	for(int i=n;i>=1;i--){
		for(int j=n;j>=i;j--){
			cout<<j<<" ";
		}

		for(int j=2*i-1;j>=1;j--){
			cout<<"  ";
		}

		for(int j=i;j<=n;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
    for(int i=n;i>=0;i--)
        cout<<i<<" ";
    for(int i=1;i<=n;i++)
        cout<<i<<" ";
    cout<<endl;
	//Lower

	for(int i=1;i<=n;i++){
		for(int j=n; j>=i;j--){
			cout<<j<<" ";
		}

		for(int j=1;j<=2*i-1;j++){
			cout<<"  ";
		}

		for(int j=i;j<=n;j++){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
