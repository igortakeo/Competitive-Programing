#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<ll> divisors(ll n){
	vector<ll>v;

	for(ll i=1; i*i <= n; i++){
		if(n%i == 0){
			v.pb(i);		
			if(i != (n/i))v.pb(n/i);
		}
	}
	return v;
}

void solve(){	
	int n, k;
	cin >> n >> k;
	
	if(k >= n){
		cout << 1 << endl;
		return;
	}	
	
	vector<ll> d = divisors(n);
	
	sort(d.rbegin(), d.rend());
	
	for(auto a : d){
		if(a <= k){
			cout << n/a << endl;	
			return;
		}
	}
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
