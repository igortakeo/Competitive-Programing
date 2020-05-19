#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
void solve(){
	ll a, b, c, d, ans=0;	
	cin >> a >> b >> c >> d;
	
	ll mx = b-a+1;
	vector<pll>v;
	
	for(ll i=c; i<=d; i++){
		ll y = i-b+1;
		if(y >= b and y <= c) v.push_back({y, 1});
		else if(b-y+1 > mx) v.push_back({b,mx});
		else if(y >= a and y <= b) v.push_back({b,b-y+1});
	}
	
	for(auto it : v){
		ll e = c-it.first+1;
		if(it.second == mx) ans+= mx*e;
		else{
			ll f = mx-it.second+1;
			if(f > e) ans += ((it.second+(mx-(f-e)))*e)/2;
			else{
				ans += ((it.second+mx)*f)/2;
				e-=f;
				ans += mx*e;
			}
		}	
	}
	
	cout << ans << endl;
	
}
 
int main(){
 
	fastcin
	solve();      
	return 0;
}
