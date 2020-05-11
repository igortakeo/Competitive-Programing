#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 20000005
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


int n, m, x;
int cost[15], v[15][15], a[15];
int ans;
	
void solve(int i, int sum){
	
	if(i > n){
		bool f = true;
		for(int j=0; j<m; j++){
			if(a[j] < x){
				f = false;
				break;
			}
		}
		if(f) ans = min(ans, sum);
		return;	
	}
	
	for(int j=0; j<m; j++) a[j]+= v[i][j];
	solve(i+1, sum+cost[i]);
	
	for(int j=0; j<m; j++) a[j] -= v[i][j];
	solve(i+1, sum);
	
	return;
}

int main(){

	fastcin
	
	cin >> n >> m >> x;
	
	for(int i=0; i<n; i++){
		cin >> cost[i];
		for(int j=0; j<m; j++) cin >> v[i][j];
	}
	
	ans = MAX;
	solve(0, 0);	
	
	if(ans != MAX) cout << ans << endl;
	else cout << -1 << endl;
	
	return 0;
}
	

