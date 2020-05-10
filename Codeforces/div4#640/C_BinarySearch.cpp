#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	
	ll n, k;
	cin >> n >> k;
	
	ll l=1, r=5*k, mid;
	
	while(l < r){
		mid = (l+r)/2;
		if((mid - mid/n) >= k) r = mid;
		else l= mid+1;	
	}
	
	cout << l << endl;
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
