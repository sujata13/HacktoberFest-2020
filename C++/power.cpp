#include <bits/stdc++.h>
#define int long long

int power(int a, int b) {
	a %= mod;
	int res = 1;
	while (b > 0) {
		if (b % 2) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return res;
}

signed main() {
    cout<<power(3,2)<<endl;
	return 0;
}