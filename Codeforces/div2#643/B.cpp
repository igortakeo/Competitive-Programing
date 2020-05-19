#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	int n, ans = 0;
	cin >> n;
	
	vector<int>v(n), a;

	for(int i=0; i<n; i++) cin >> v[i];
		
	sort(v.begin(), v.end());
		
	for(int i=0; i<n; i++){
		a.pb(v[i]);
		if(a.size() >= v[i]){
			ans++;	
			a.clear();
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
	
