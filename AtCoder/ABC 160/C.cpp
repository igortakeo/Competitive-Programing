#include <bits/stdc++.h>

using namespace std;

int main(){

	int k, n;
	cin >> k >> n;

	int v[n], u[n];

	for(int i=0; i<n; i++) cin >> v[i];

	for(int i=1; i<n; i++) u[i-1] = v[i]-v[i-1];

	u[n-1] = k-v[n-1] + v[0];

	sort(u, u+n);

	int ans = 0;

	for(int i=0; i<n-1; i++) ans+=u[i];	

	cout << ans << endl;


	return 0;
}