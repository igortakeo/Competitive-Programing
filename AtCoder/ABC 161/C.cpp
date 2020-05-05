#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	ll n, m;
	cin >> n >> m;
	
	if(n == m or n%m == 0) cout << 0 << endl;
	else if(n > m){
		ll d = n/m;
		cout << min(abs(n-m*d), abs(n-m*(d+1))) << endl;;
	}
	else{
		cout << min(m-n, n) << endl;
	}
	
	return 0;
}
