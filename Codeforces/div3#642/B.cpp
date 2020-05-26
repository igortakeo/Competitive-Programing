#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n), b(n);
	
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	
	
	for(int i=0; i<k; i++){
		if(a[i] < b[i]) swap(a[i], b[i]);
		else break;
	}	
	
	int sum = 0;
	for(int i=0; i<n; i++) sum+=a[i];
	
	cout << sum << endl;
	
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
	

