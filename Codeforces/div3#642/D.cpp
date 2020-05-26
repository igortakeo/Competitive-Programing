#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sd second
#define ft first
using namespace std;

void solve(){
	
	int n, k=1;
	cin >> n;
	
	int ans[n+1];
	memset(ans, 0, sizeof ans);
	
	int l=1, r=n;
	priority_queue<pair<int, pii>>pq;
	pq.push({r-l,{-l, -r}});
	ans[0] = -1;
	
	while(!pq.empty()){
		auto a = pq.top();
		pq.pop();
		
		l = -a.sd.ft;
		r = -a.sd.sd; 
		
		int mid  = (l+r)/2;
		ans[mid] = k;
		k++;
		if(k > n) break;
		if(mid-1 > 0)pq.push({mid-l, {-l, -(mid-1)}});
		if(mid+1 <= n)pq.push({r-mid, {-(mid+1), -r}});
	}
	
	
	for(int i=1; i<=n; i++) cout << ans[i] << ' ';
	cout << endl;
}

int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--) solve();
	      
	return 0;
}
