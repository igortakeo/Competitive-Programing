#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){	
	int n;
	cin >> n;
	
	int v[n];
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	sort(v, v+n);
	
	int ans = 5000;
	
	for(int i=0; i<n-1; i++){
		int diff = v[i+1]-v[i];
		ans = min(diff, ans);
	}
	
	cout << ans <<endl;	
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	
