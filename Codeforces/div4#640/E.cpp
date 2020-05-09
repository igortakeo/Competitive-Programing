#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fastcin  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


int main(){

	fastcin
	
	int t;
	cin >> t;
	
	while(t--){
		int n, ans = 0, sum = 0;
		cin >> n;
		
		int v[n];
		bool vis[8000];
		memset(vis, false, sizeof vis);
		
			
		for(int i=0; i<n; i++) cin >> v[i];
		
		for(int i=0; i<n; i++){
			sum = v[i];
			for(int j=i+1; j<n; j++){
				sum += v[j];
				if(sum > n) break;
				vis[sum] = true;
			}
			sum = 0;
		}
		
		
		for(int i=0; i<n; i++){
			if(vis[v[i]]) ans++;
		}
		
		cout << ans << endl;
		
	}
	 
	return 0;
}
	
