#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, k;
	
	cin >> n >> k;
	
	vector<int>v(n), u(n), ans(n);
	
	int m[n];
	memset(m, 0, sizeof m);
	
	for(int i=0; i<n; i++) cin >> v[i];
	
	u = v;
	
	sort(u.begin(), u.end());
	
	int x, y;
	for(int i=0; i<k; i++){
		cin >> x >> y;
		
		if(v[x-1] > v[y-1])m[x-1]++;
		else if(v[y-1] > v[x-1])m[y-1]++;
		
	}
	
	for(int i=0; i<n; i++){
		auto it = lower_bound(u.begin(), u.end(), v[i]);
		ans[i] = (it - u.begin())-m[i];
	}	
	
	for(auto a : ans) cout << a << ' ';
	cout << endl;
	
	return 0;
} 
