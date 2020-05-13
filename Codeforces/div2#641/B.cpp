#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 200000
using namespace std;

vector<int> divisors(int n){

	vector<int>v;

	for(int i=1; i*i <= n; i++){
		if(n%i == 0){
			v.pb(i);		
			if(i != (n/i))v.pb(n/i);
		}
	}	
	
	return v;
}

void solve(){
	int n;
	cin >> n;
	int v[n+1];
	for(int i=1; i<=n; i++) cin >> v[i];
	
	int dp[n+1], ans = 0;
	
	for(int i=1;i<=n; i++) dp[i] = 1;
	
	for(int i=n; i>=1; i--){
		vector<int> d  = divisors(i);
		for(auto it : d){
			if(v[it] < v[i]) dp[it] = max(dp[it], dp[i]+1);
			ans = max(ans, dp[it]);
		}
	}	
	
	cout << ans << endl;
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	

