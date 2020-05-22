#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	ll v[n];
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	sort(v, v+n);
	
	cout << max(v[n-1]*v[n-2]*v[n-3], v[0]*v[1]*v[n-1]) << endl;
	
}

int main(){
	fastcin
	solve();      
	return 0;
}
	
