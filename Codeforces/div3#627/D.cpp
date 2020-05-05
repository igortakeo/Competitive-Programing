#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<ll> a(n), b(n), diff(n);

	for(int i=0; i<n; i++)cin >> a[i];

	for(int i=0; i<n; i++)cin >> b[i];


	for(int i=0; i<n; i++) diff[i] = a[i] - b[i];

	sort(diff.begin(), diff.end());

	ll ans=0; 
	
	for(int i=0; i<diff.size(); i++){
		if(diff[i] > 0){
			auto j = lower_bound(diff.begin(), diff.end(), -diff[i]+1);
			ll k = j-diff.begin();
			ans += i-k;
		}
	}


	cout << ans << endl;


	return 0;
}