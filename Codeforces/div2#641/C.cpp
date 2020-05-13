#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	ll n;
	cin >> n;
	
	ll v[n];
	ll array_gcd[n];
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	array_gcd[n-1] = v[n-1];
	
	for(int i=n-2; i>=0; i--) array_gcd[i] = __gcd(array_gcd[i+1], v[i]);
	
	vector<ll>d;
	
	for(int i=0; i<n-1; i++) d.push_back((v[i]*array_gcd[i+1]*1ll)/array_gcd[i]);
	
	ll ans = d[0];
	for(int i=1; i<d.size(); i++)ans = __gcd(ans, d[i]);
	
	cout << ans << endl;
	
}

int main(){

	fastcin
	solve();      
	return 0;
}
	
