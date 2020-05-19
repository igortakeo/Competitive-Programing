#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll maxD(ll n){
	ll a = -1;	
	while(n > 0){
		a = max(a, n%10);
		n/=10;
	}	
	return a;
} 

ll minD(ll n){
	ll a = 10;	
	while(n > 0){
		a = min(a, n%10);
		n/=10;
	}	
	return a;
}

void solve(){
	
	ll n, k;
	cin >> n >> k;

	while(k-- > 1){
		ll mn = minD(n);	
		ll mx = maxD(n);	
		if(mn*mx == 0) break;	
		n+=mn*mx;
	}
	
	cout << n << endl;
}

int main(){

	fastcin	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
