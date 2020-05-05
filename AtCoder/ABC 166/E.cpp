#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

map<ll, ll>freq;

int main(){

	fastcin
	
	ll n, ans=0;
	cin >> n;
	
	ll v[n+1];
	
	for(int i=1; i<=n; i++) cin >> v[i];
	
	for(int i=1; i<=n; i++){
		freq[i+v[i]]++;
	}	
	
	for(int i=1; i<=n; i++){
		if(i-v[i] >= 0) ans+=freq[i-v[i]];
	}
	
	cout << ans << endl;
	      
	return 0;
}
