#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){

	fastcin
	
	int n, m;
	cin >> n >> m;
	
	int v[m], sum = 0; 
	
	for(int i=0; i<m; i++) cin >> v[i];
	
	for(int i=0; i<m; i++) sum+= v[i];
	
	
	int ans;
	
	(sum > n) ? ans = -1 : ans = n-sum;	
	
	cout << ans << endl;
	      
	return 0;
}
