#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	
	ll n;
	cin >> n;
	
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	if(n == 3){
		cout << 8 <<endl;
		return;
	}
	
	ll d = 8;
	ll k = (n-3)/2+1;
	ll sum = 0;
	
	while(k > 0){
		sum += (d*k)*k;
		k--;
	}
	cout << sum << endl;
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
